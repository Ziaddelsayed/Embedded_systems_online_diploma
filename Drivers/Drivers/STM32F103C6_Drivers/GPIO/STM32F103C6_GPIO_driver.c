/*
 * STM32F103C6_GPIO_driver.c
 *
 *  Created on: Dec 6, 2024
 *      Author: Ziad El-Sayed
 */
#include "STM32F103C6_GPIO_driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch(PinNumber)
	{
//CRL
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
		return 4;
		break;
	case GPIO_PIN_2:
		return 8;
		break;
	case GPIO_PIN_3:
		return 12;
		break;
	case GPIO_PIN_4:
		return 16;
		break;
	case GPIO_PIN_5:
		return 20;
		break;
	case GPIO_PIN_6:
		return 24;
		break;
	case GPIO_PIN_7:
		return 28;
		break;
//CRH
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_15:
		return 28;
		break;
	}
return 0;
}

 /**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief			-Initializes the GPIOx PINy according to the specific parameters in the pinConfig.
 * @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
 * @param [IN]		-pinConfig: pointer to GPIO_PinConfig_t structure that contains
 * 					 the configuration information for specific GPIO PIN.
 * @retval			-None
 * Note				-STM32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					 but LQFP48 has only GPIO A,B,PART of C/D exported as external PINS from the MCU.
 */
void MCAL_GPIO_Init (GPIO_t* GPIOx,GPIO_pinConfig_t* pinconfig)
{
	//Port configure register low (GPIOX_CRL) configures pins 0>>7.
	//Port configure register high (GPIOX_CRH) configures pins 8>>15.
	volatile uint32_t* configregister= NULL;
	uint8_t PIN_Config = 0;
	configregister= (pinconfig->GPIO_pinNumber < GPIO_PIN_8)? &GPIOx->CRL:&GPIOx->CRH ;
	//clear CNF0[1:0] & MODE0[1:0]
	(*configregister) &= ~(0xf << Get_CRLH_Position(pinconfig->GPIO_pinNumber));
	//if pin is output
	if((pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD) || (pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (pinconfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		//Set CNF0[1:0] & MODE0[1:0]
		PIN_Config = ((((pinconfig->GPIO_MODE -4) << 2) | (pinconfig->GPIO_Output_Speed)) & 0x0f);

	}
	else
	{
		if((pinconfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (pinconfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//Set CNF0[1:0] & MODE0[1:0]00
			PIN_Config = ((((pinconfig->GPIO_MODE) << 2) | 0x0) & 0x0f);

		}
		else if(pinconfig->GPIO_MODE == GPIO_MODE_AF_INPUT)//consider it as input floating
		{
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) << 2) | 0x0) & 0x0f);
		}
		else //PU or PD INPUT
		{
			PIN_Config = ((((GPIO_MODE_INPUT_PU) << 2) | 0x0) & 0x0f);
			//Table 20. Port bit configuration table pull up PxODR 1
			if(pinconfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//Table 20. Port bit configuration table pull up PxODR 1
				GPIOx->ODR |= pinconfig->GPIO_pinNumber;
			}
			else//Table 20. Port bit configuration table pull down PxODR 0
			{
				//Table 20. Port bit configuration table pull down PxODR 0
				GPIOx->ODR &= ~(pinconfig->GPIO_pinNumber);

			}

		}

		}
	//write on CRL or CRH
	(*configregister) |= ((PIN_Config) << Get_CRLH_Position(pinconfig->GPIO_pinNumber));


}

/**================================================================
* @Fn				-MCAL_GPIO_DeInit
* @brief			-Reset all the GPIOx PINy.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @retval			-None
* Note				-None
*/
void MCAL_GPIO_DeInit (GPIO_t* GPIOx)
{
	//you can reset each register with its reset value
	//or u can use the reset controller if it  exists
	//set and cleared by software
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=  (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=  (1<<3);
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=  (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=  (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}

}




/**================================================================
* @Fn				-MCAL_GPIO_ReadPin
* @brief			-Read specific PIN.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @param [IN]		-PinNumber:Set PinNumber according to @ref GPIO_PINS_define.
* @retval			-The input pin value (two values based on @ref GPIO_PIN_State).
* Note				-None
*/
uint8_t MCAL_GPIO_ReadPin (GPIO_t* GPIOx,uint16_t PinNumber)
{
	uint8_t bitstatues;
	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatues = GPIO_PIN_SET ;
	}
	else{
		bitstatues = GPIO_PIN_RESET ;
	}
return bitstatues;
}




/**================================================================
* @Fn				-MCAL_GPIO_ReadPort
* @brief			-Read specific PORT.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @retval			-The input port value.
* Note				-None
*/
uint16_t MCAL_GPIO_ReadPort (GPIO_t* GPIOx)
{
	uint16_t PortVal;
	PortVal = (uint16_t)(GPIOx->IDR);
	return PortVal;

}


/**================================================================
* @Fn				-MCAL_GPIO_WritePin.
* @brief			-Write on specific output PIN.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @param [IN]		-PinNumber:Set PinNumber according to @ref GPIO_PINS_define.
* @param [IN]		-value: Pin value.
* @retval			-None.
* Note				-None.
*/
void MCAL_GPIO_WritePin (GPIO_t* GPIOx,uint16_t PinNumber,uint8_t Value)
{

	if(Value != GPIO_PIN_RESET)
	{
		//GPIOx->ODR |= PinNumber ;
		//or
		//These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else{
		// Bits 15:0BRy: Port x Reset bit y (y= 0 .. 15)
		// These bits are write-only and can be accessed in Word mode only.
		//0: No action on the corresponding ODRx bit
		//1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;
	}

}





/**================================================================
* @Fn				-MCAL_GPIO_WritePort.
* @brief			-Write on specific output PORT.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @param [IN]		-value: Port value.
* @retval			-None.
* Note				-None.
*/
void MCAL_GPIO_WritePort (GPIO_t* GPIOx,uint16_t Value)
{
	GPIOx->ODR = (uint32_t)Value;

}




/**================================================================
* @Fn				-MCAL_GPIO_TogglePin.
* @brief			-Toggle specific PIN.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @param [IN]		-PinNumber:Set PinNumber according to @ref GPIO_PINS_define.
* @retval			-None.
* Note				-None.
*/
void MCAL_GPIO_TogglePin (GPIO_t* GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;

}




/**================================================================
* @Fn				-MCAL_GPIO_LockPin.
* @brief			-Lock specific PIN.
* @param [IN]		-GPIOx: where x can be (A...E depending on device used) to select the GPIO peripheral.
* @param [IN]		-PinNumber:Set PinNumber according to @ref GPIO_PINS_define.
* @retval			-Ok if pin config is locked or Error if the pin is not locked (Ok & Error are defined @ref GPIO_RETURN_LOCK).
* Note				-None.
*/
uint8_t MCAL_GPIO_LockPin (GPIO_t* GPIOx,uint16_t PinNumber)
{
	 //Bit 16 LCKK[16]: Lock key
	 //This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	 //0: Port configuration lock key not active
	 //1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	 //LOCK key writing sequence:
	 //Write 1
	 //Write 0
	 //Write 1
	 //Read 0
	 //Read 1 (this read is optional but confirms that the lock is active)
	 //Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	 //Any error in the lock sequence will abort the lock.
	 //Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	 //These bits are read write but can only be written when the LCKK bit is 0.
	 //0: Port configuration not locked
	 //1: Port configuration locked.
//set LCKK[16]
 volatile uint32_t temp = 1<<16;
//set LCKy:
 temp |= PinNumber;
 //Write 1
 GPIOx->LCKR = temp;
 //Write 0
 GPIOx->LCKR = PinNumber;
 //Write 1
 GPIOx->LCKR = temp;
 //Read 0
 temp =  GPIOx->LCKR;
 //Read 1 (this read is optional but confirms that the lock is active)
 if((uint32_t)(GPIOx->LCKR & 1 << 16))
 {
	 return GPIO_RETURN_LOCK_Enabled ;
 }
 else{
	 return GPIO_RETURN_LOCK_Error ;
 }

}
