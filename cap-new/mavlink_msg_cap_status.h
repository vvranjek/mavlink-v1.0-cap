// MESSAGE CAP_STATUS PACKING

#define MAVLINK_MSG_ID_CAP_STATUS 180

typedef struct MAVLINK_PACKED __mavlink_cap_status_t
{
 uint8_t parachute_status; /*< Status of the prachute*/
 uint8_t airspeed_cal; /*< Status of the airspeed sensor calibration*/
 uint8_t home_init; /*< Status of home location*/
} mavlink_cap_status_t;

#define MAVLINK_MSG_ID_CAP_STATUS_LEN 3
#define MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN 3
#define MAVLINK_MSG_ID_180_LEN 3
#define MAVLINK_MSG_ID_180_MIN_LEN 3

#define MAVLINK_MSG_ID_CAP_STATUS_CRC 123
#define MAVLINK_MSG_ID_180_CRC 123



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_CAP_STATUS { \
	180, \
	"CAP_STATUS", \
	3, \
	{  { "parachute_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cap_status_t, parachute_status) }, \
         { "airspeed_cal", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cap_status_t, airspeed_cal) }, \
         { "home_init", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cap_status_t, home_init) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_CAP_STATUS { \
	"CAP_STATUS", \
	3, \
	{  { "parachute_status", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_cap_status_t, parachute_status) }, \
         { "airspeed_cal", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_cap_status_t, airspeed_cal) }, \
         { "home_init", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_cap_status_t, home_init) }, \
         } \
}
#endif

/**
 * @brief Pack a cap_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param parachute_status Status of the prachute
 * @param airspeed_cal Status of the airspeed sensor calibration
 * @param home_init Status of home location
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cap_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t parachute_status, uint8_t airspeed_cal, uint8_t home_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAP_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, parachute_status);
	_mav_put_uint8_t(buf, 1, airspeed_cal);
	_mav_put_uint8_t(buf, 2, home_init);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAP_STATUS_LEN);
#else
	mavlink_cap_status_t packet;
	packet.parachute_status = parachute_status;
	packet.airspeed_cal = airspeed_cal;
	packet.home_init = home_init;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAP_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CAP_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
}

/**
 * @brief Pack a cap_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param parachute_status Status of the prachute
 * @param airspeed_cal Status of the airspeed sensor calibration
 * @param home_init Status of home location
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_cap_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t parachute_status,uint8_t airspeed_cal,uint8_t home_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAP_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, parachute_status);
	_mav_put_uint8_t(buf, 1, airspeed_cal);
	_mav_put_uint8_t(buf, 2, home_init);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_CAP_STATUS_LEN);
#else
	mavlink_cap_status_t packet;
	packet.parachute_status = parachute_status;
	packet.airspeed_cal = airspeed_cal;
	packet.home_init = home_init;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_CAP_STATUS_LEN);
#endif

	msg->msgid = MAVLINK_MSG_ID_CAP_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
}

/**
 * @brief Encode a cap_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param cap_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cap_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_cap_status_t* cap_status)
{
	return mavlink_msg_cap_status_pack(system_id, component_id, msg, cap_status->parachute_status, cap_status->airspeed_cal, cap_status->home_init);
}

/**
 * @brief Encode a cap_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param cap_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_cap_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_cap_status_t* cap_status)
{
	return mavlink_msg_cap_status_pack_chan(system_id, component_id, chan, msg, cap_status->parachute_status, cap_status->airspeed_cal, cap_status->home_init);
}

/**
 * @brief Send a cap_status message
 * @param chan MAVLink channel to send the message
 *
 * @param parachute_status Status of the prachute
 * @param airspeed_cal Status of the airspeed sensor calibration
 * @param home_init Status of home location
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_cap_status_send(mavlink_channel_t chan, uint8_t parachute_status, uint8_t airspeed_cal, uint8_t home_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[MAVLINK_MSG_ID_CAP_STATUS_LEN];
	_mav_put_uint8_t(buf, 0, parachute_status);
	_mav_put_uint8_t(buf, 1, airspeed_cal);
	_mav_put_uint8_t(buf, 2, home_init);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAP_STATUS, buf, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
#else
	mavlink_cap_status_t packet;
	packet.parachute_status = parachute_status;
	packet.airspeed_cal = airspeed_cal;
	packet.home_init = home_init;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAP_STATUS, (const char *)&packet, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
#endif
}

/**
 * @brief Send a cap_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_cap_status_send_struct(mavlink_channel_t chan, const mavlink_cap_status_t* cap_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_cap_status_send(chan, cap_status->parachute_status, cap_status->airspeed_cal, cap_status->home_init);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAP_STATUS, (const char *)cap_status, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_CAP_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_cap_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t parachute_status, uint8_t airspeed_cal, uint8_t home_init)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char *buf = (char *)msgbuf;
	_mav_put_uint8_t(buf, 0, parachute_status);
	_mav_put_uint8_t(buf, 1, airspeed_cal);
	_mav_put_uint8_t(buf, 2, home_init);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAP_STATUS, buf, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
#else
	mavlink_cap_status_t *packet = (mavlink_cap_status_t *)msgbuf;
	packet->parachute_status = parachute_status;
	packet->airspeed_cal = airspeed_cal;
	packet->home_init = home_init;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_CAP_STATUS, (const char *)packet, MAVLINK_MSG_ID_CAP_STATUS_MIN_LEN, MAVLINK_MSG_ID_CAP_STATUS_LEN, MAVLINK_MSG_ID_CAP_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE CAP_STATUS UNPACKING


/**
 * @brief Get field parachute_status from cap_status message
 *
 * @return Status of the prachute
 */
static inline uint8_t mavlink_msg_cap_status_get_parachute_status(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field airspeed_cal from cap_status message
 *
 * @return Status of the airspeed sensor calibration
 */
static inline uint8_t mavlink_msg_cap_status_get_airspeed_cal(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field home_init from cap_status message
 *
 * @return Status of home location
 */
static inline uint8_t mavlink_msg_cap_status_get_home_init(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a cap_status message into a struct
 *
 * @param msg The message to decode
 * @param cap_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_cap_status_decode(const mavlink_message_t* msg, mavlink_cap_status_t* cap_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	cap_status->parachute_status = mavlink_msg_cap_status_get_parachute_status(msg);
	cap_status->airspeed_cal = mavlink_msg_cap_status_get_airspeed_cal(msg);
	cap_status->home_init = mavlink_msg_cap_status_get_home_init(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_CAP_STATUS_LEN? msg->len : MAVLINK_MSG_ID_CAP_STATUS_LEN;
        memset(cap_status, 0, MAVLINK_MSG_ID_CAP_STATUS_LEN);
	memcpy(cap_status, _MAV_PAYLOAD(msg), len);
#endif
}
