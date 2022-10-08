/*
 * USART.h
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmad
 */

#ifndef INC_USART_H_
#define INC_USART_H_

typedef enum {
    USART_NOT_COMPLETE,
    USART_COMPLETE
} Usart_StateType;

typedef enum {
    USART_INT_SOURCE_RX,
    USART_INT_SOURCE_TX,
    USART_INT_SOURCE_EMPTY
} Usart_InterruptSourceType;

void Usart_Init (void);
void Usart_Transmit (u8 data);
void Usart_TransmitASync (u8 data);
u8 Usart_Receive (void);
Usart_StateType Usart_ReceiveAsync (u8 *data);
void Usart_EnableNotification (Usart_InterruptSourceType source);
void Usart_DisableNotification (Usart_InterruptSourceType source);
void Usart_SetCallbackReceive(void (*callback) (u8 data));
void Usart_SetCallbackTransmit(void (*callback) (void));
void Usart_SetCallbackEmpty(void (*callback) (void));
void Usart_SendString(u8 *str);
void Usart_SendNumber(s32 num);
void Usart_Print(u8 *str, ...);
#endif /* INC_USART_H_ */
