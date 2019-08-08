#ifndef GPT_H 
#define	GPT_H 

/*****************************************************************************/
/********************************** zone type_def ****************************/
/*****************************************************************************/

/* !Description : Modes of the GPT driver.                                   */
/* !Trace_To    : Covers_SRS_BSW_00441, Covers_SRS_BSW_00305                 */
/* !Type        : Enumeration                                                */
typedef enum
{
	GPT_MODE_NORMAL = 0x00,
	GPT_MODE_SLEEP = 0x01
}Gpt_ModeType;

/* !Description : Type for GPT Predef Timers                                 */
/* !Trace_To    : Covers_SRS_Gpt_13605                                       */
/* !Type        : Enumeration                                                */
typedef enum
{
	GPT_PREDEF_TIMER_1US_16BIT = 0x00,
	GPT_PREDEF_TIMER_1US_24BIT,
	GPT_PREDEF_TIMER_1US_32BIT,
	GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimerType;

/*****************************************************************************/
/********************************** zone macro *******************************/
/*****************************************************************************/

/*****************************************************************************/
/********************************** zone define ******************************/
/*****************************************************************************/

/*****************************************************************************/
/********************************* zone constant *****************************/
/*****************************************************************************/

/*****************************************************************************/
/********************************* zone struct/union *************************/
/*****************************************************************************/
/* !Description : This is the type of the data structure including the       */
/*         configuration set required for initializing the GPT timer unit.   */
/* !Trace_To    : Covers_SRS_BSW_00404, Covers_SRS_BSW_00405,                */
/*                 Covers_SRS_BSW_00305, Covers_SRS_BSW_00414,               */
/*                 Covers_SRS_SPAL_12263, Covers_SRS_BSW_00438               */
/* !Type        : struct                                                     */
typedef struct
{
	
}Gpt_ConfigType;
/******************************************************************************/
/********************************* zone variable ******************************/
/******************************************************************************/
/* !Description : Numeric ID of a GPT channel.                                */
/* !Trace_To    : Covers_SRS_BSW_00305, Covers_SRS_SPAL_12063,                */ 
/*                Covers_SRS_Gpt_12328)                                       */
/* !Type        : uint                                                        */
uint Gpt_ChannelType;

/* !Description : Type for reading and setting the timer values               */
/*                (in number of ticks).                                       */
/* !Trace_To    : Covers_SRS_BSW_00305                                        */
/* !Type        : uint                                                        */
uint Gpt_ValueType;

/******************************************************************************/
/********************************* zone function ******************************/
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/* !Description : Returns the version information of this module.             */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : VersionInfoPtr                 */
/*                                    * Type : Std_VersionInfoType*           */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SRS_BSW_00407                                        */
/* !Service ID[hex] : 0x00                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant                                                   */
/******************************************************************************/
void Gpt_GetVersionInfo( Std_VersionInfoType* VersionInfoPtr );

/******************************************************************************/
/* !Description : Initializes the GPT driver.                                 */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : ConfigPtr                      */
/*                                    * Type : const Gpt_ConfigType*          */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00280                                        */
/* !Service ID[hex] : 0x01                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Non Reentrant                                               */
/******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr );

/******************************************************************************/
/* !Description : Deinitializes the GPT driver.                               */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : None                           */
/*                                    * Type : None                           */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : Npne                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00281                                        */
/* !Service ID[hex] : 0x02                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Non Reentrant                                               */
/******************************************************************************/
void Gpt_DeInit( void );

/******************************************************************************/
/* !Description : Returns the time remaining until the target time is reached.*/
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Channel                        */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : Elapsed timer value (in number of ticks):                   */
/*                                    * Name :                                */
/*                                    * Type : Gpt_ValueType                  */
/*                                    * Range:                                */
/* !Trace_To    : Covers_SWS_Gpt_00282                                        */
/* !Service ID[hex] : 0x03                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant                                                   */
/******************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Returns the time already elapsed.                           */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Channel                        */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : Remaining timer value(in number of ticks):                  */
/*                                    * Name :                                */
/*                                    * Type : Gpt_ValueType                  */
/*                                    * Range:                                */
/* !Trace_To    : Covers_SWS_Gpt_00283                                        */
/* !Service ID[hex] : 0x04                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant                                                   */
/******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Starts a timer channel.                                     */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Value                          */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/*                - Function Value :                                          */
/*                                    * Name : Channel                        */
/*                                    * Type : Gpt_ValueType                  */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00284                                        */
/* !Service ID[hex] : 0x05                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );

/******************************************************************************/
/* !Description : Stops a timer channel .                                     */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Value                          */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00285                                        */
/* !Service ID[hex] : 0x06                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Enables the interrupt notification for a channel            */
/*                 (relevant in normal mode).                                 */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Value                          */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00286                                        */
/* !Service ID[hex] : 0x07                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_EnableNotification( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Disables the interrupt notification for a channel           */
/*                 (relevant in normal mode).                                 */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Value                          */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00287                                        */
/* !Service ID[hex] : 0x08                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_DisableNotification( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Sets the operation mode of the GPT.                         */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Mode                           */
/*                                    * Type : Gpt_ModeType                   */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00288                                        */
/* !Service ID[hex] : 0x09                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Non Reentrant                                               */
/******************************************************************************/

void Gpt_SetMode( Gpt_ModeType Mode );

/******************************************************************************/
/* !Description : Disables the wakeup interrupt of a channel                  */
/*                (relevant in sleep mode).                                   */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Channel                        */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00289                                        */
/* !Service ID[hex] : 0x0a                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_DisableWakeup( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Enables the wakeup interrupt of a channel                   */
/*                (relevant in sleep mode).                                   */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : Channel                        */
/*                                    * Type : Gpt_ChannelType                */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00290                                        */
/* !Service ID[hex] : 0x0b                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant(but not for the same timer channel)               */
/******************************************************************************/
void Gpt_EnableWakeup( Gpt_ChannelType Channel );

/******************************************************************************/
/* !Description : Checks if a wakeup capable GPT channel is the source for    */
/*                a wakeup event and calls the ECU state manager service      */
/*            EcuM_SetWakeupEvent in case of a valid GPT channel wakeup event.*/
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : WakeupSource                   */
/*                                    * Type : EcuM_WakeupSourceType          */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : None                                                        */
/* !Trace_To    : Covers_SWS_Gpt_00328                                        */
/* !Service ID[hex] : 0x0c                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant                                                   */
/******************************************************************************/
void Gpt_CheckWakeup( EcuM_WakeupSourceType WakeupSource );

/******************************************************************************/
/* !Description : Delivers the current value of the desired GPT Predef Timer. */
/* !Input       :                                                             */
/*                - Function Value :                                          */
/*                                    * Name : PredefTimer                    */
/*                                    * Type : Gpt_PredefTimerType            */
/*                                    * Range:                                */
/*                - Function Value :                                          */
/*                                    * Name : TimeValuePtr                   */
/*                                    * Type : uint32*                        */
/*                                    * Range:                                */
/* !In/Out      : None                                                        */
/* !Output      : E_OK: no error has been detected                            */
/*                  E_NOT_OK: aborted due to errors                           */
/*                                    * Name :                                */
/*                                    * Type : Std_ReturnType                 */
/*                                    * Range:                                */
/* !Trace_To    : Covers_SWS_Gpt_00394                                        */
/* !Service ID[hex] : 0x0d                                                    */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : Reentrant                                                   */
/******************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue( Gpt_PredefTimerType PredefTimer, uint32* TimeValuePtr );

/******************************************************************************/
/* !Description : -                                                           */
/* !Input       : None                                                        */
/* !In/Out      : None                                                        */
/* !Output      :                                                             */
/* !Trace_To    : Covers_SWS_BSW_00375,Covers_SRS_SPAL_12069                  */
/* !Service ID[hex] : -                                                       */
/* Sync/Async   : Synchronous                                                 */
/* Reentrancy   : GPT user implementation dependant.                          */
/******************************************************************************/
void Gpt_Notification_<channel>( void );

#endif	/* GPT_H */
