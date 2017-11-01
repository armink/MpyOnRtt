#ifndef SPI_SLAVE_H_INCLUDED
#define SPI_SLAVE_H_INCLUDED

#include <stdint.h>

typedef enum
{
    spi_state_ready = 0,
    //spi_state_cmd_start,
    spi_state_cmd,
    //spi_state_cmd_stop,
    //spi_state_cmd_handle,
    //spi_state_busy
    //spi_state_resp,
    //spi_state_data,
    //spi_state_finish,
}
spi_state_typedef;

// little-endian
struct cmd_request
{
    uint32_t flag;
    uint32_t M2S_len; // master to slave data len.
    uint32_t magic1;
    uint32_t magic2;
};

#define CMD_MAGIC1          (0x67452301)
#define CMD_MAGIC2          (0xEFCDAB89)

#define CMD_FLAG_MRDY       (0x01)

// little-endian
struct response
{
    uint32_t flag;
    uint32_t S2M_len; // slave to master data len.
    uint32_t magic1;
    uint32_t magic2;
};

#define RESP_FLAG_SRDY      (0x01)
#define RESP_MAGIC1         (0x98BADCFE)
#define RESP_MAGIC2         (0x10325476)

/* spi slave configure. */
#define MAX_DATA_LEN        1520
#define SPI_RX_POOL_SIZE    3
#define SPI_TX_POOL_SIZE    3

// align check
#if (MAX_DATA_LEN & 0x03) != 0
#error MAX_DATA_LEN must ALIGN to 4byte!
#endif

typedef enum
{
    data_type_eth_data = 0,
    data_type_cmd,
    data_type_resp,
}
app_data_type_typedef;

struct spi_data_packet
{
    uint32_t data_len;
    uint32_t data_type;
    char buffer[MAX_DATA_LEN];
};

#define SPI_BUFFER_LEN      (MAX_DATA_LEN + sizeof(struct response))
extern uint8_t spi_hw_rx_buffer[SPI_BUFFER_LEN];
extern uint8_t spi_hw_tx_buffer[SPI_BUFFER_LEN];

extern struct rt_mempool spi_rx_mp;
extern struct rt_mempool spi_tx_mp;
extern struct rt_mailbox spi_rx_mb;
extern struct rt_mailbox spi_tx_mb;

/* spi slave API. */
void spi_slave_init(void);
void cs_falling_irq(void);
void cs_rising_irq(void);

/* spi slave hw API. */
void spi_slave_hw_init(void);
void spi_prepare(void);
void spi_busy(rt_bool_t st);
void spi_irq_request(void);

/* tools */
#define node_entry(node, type, member) \
    ((type *)((char *)(node) - (unsigned long)(&((type *)0)->member)))
#define member_offset(type, member) \
    ((unsigned long)(&((type *)0)->member))

#endif // SPI_SLAVE_H_INCLUDED
