/* @file
 * @brief Internal APIs for Audio Stream handling

 * Copyright (c) 2020 Intel Corporation
 * Copyright (c) 2021-2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdbool.h>

#include <zephyr/bluetooth/audio/audio.h>
#include <zephyr/bluetooth/audio/bap.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/iso.h>

void bt_bap_stream_init(struct bt_bap_stream *stream);

/* Disconnect ISO channel */
int bt_bap_stream_disconnect(struct bt_bap_stream *stream);

void bt_bap_stream_reset(struct bt_bap_stream *stream);

void bt_bap_stream_attach(struct bt_conn *conn, struct bt_bap_stream *stream, struct bt_bap_ep *ep,
			  struct bt_audio_codec_cfg *codec_cfg);

void bt_bap_qos_cfg_to_iso_qos(struct bt_iso_chan_io_qos *io, const struct bt_bap_qos_cfg *qos_cfg);

void bt_bap_stream_detach(struct bt_bap_stream *stream);

enum bt_bap_ascs_reason bt_audio_verify_qos(const struct bt_bap_qos_cfg *qos);
bool bt_audio_valid_codec_cfg(const struct bt_audio_codec_cfg *codec_cfg);
bool bt_bap_valid_qos_pref(const struct bt_bap_qos_cfg_pref *qos_pref);
bool bt_bap_stream_can_disconnect(const struct bt_bap_stream *stream);

enum bt_bap_ascs_reason bt_bap_stream_verify_qos(const struct bt_bap_stream *stream,
						 const struct bt_bap_qos_cfg *qos);

struct bt_iso_chan *bt_bap_stream_iso_chan_get(struct bt_bap_stream *stream);
