/*
 * Copyright (c) 2011-2012, 2014-2020 The Linux Foundation. All rights reserved.
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**=========================================================================

   \file  rrm_api.h

   \brief RRM APIs

   ========================================================================*/

/* $Header$ */

#ifndef __RRM_API_H__
#define __RRM_API_H__

#define RRM_BCN_RPT_NO_BSS_INFO    0
#define RRM_BCN_RPT_MIN_RPT        1
#define RRM_CH_BUF_LEN             45

QDF_STATUS rrm_initialize(struct mac_context *mac);

QDF_STATUS rrm_cleanup(struct mac_context *mac);

QDF_STATUS rrm_process_link_measurement_request(struct mac_context *mac,
						uint8_t *pRxPacketInfo,
						tDot11fLinkMeasurementRequest
							  *pLinkReq,
						struct pe_session *
							  pe_session);
/*
 * rrm_process_radio_measurement_request - Processes the Radio Resource
 * Measurement request
 *
 * @mac_ctx: Global pointer to MAC context
 * @peer: Macaddress of the peer requesting the radio measurement.
 * @rrm_req: Array of Measurement request IEs
 * @session_entry: session entry.
 * @error_code: beacon report resp error code
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
rrm_process_radio_measurement_request(struct mac_context *mac_ctx,
				      tSirMacAddr peer,
				      tDot11fRadioMeasurementRequest *rrm_req,
				      struct pe_session *session_entry,
				      enum beacon_report_status_code
				      error_code);

QDF_STATUS rrm_process_neighbor_report_response(struct mac_context *mac,
						tDot11fNeighborReportResponse
							  *pNeighborRep,
						struct pe_session *
							  pe_session);

QDF_STATUS rrm_send_set_max_tx_power_req(struct mac_context *mac,
					 int8_t txPower,
					 struct pe_session *pe_session);

int8_t rrm_get_mgmt_tx_power(struct mac_context *mac,
			     struct pe_session *pe_session);

void rrm_cache_mgmt_tx_power(struct mac_context *mac,
			     int8_t txPower, struct pe_session *pe_session);

tpRRMCaps rrm_get_capabilities(struct mac_context *mac,
			       struct pe_session *pe_session);

void rrm_get_start_tsf(struct mac_context *mac, uint32_t *pStartTSF);

QDF_STATUS rrm_set_max_tx_power_rsp(struct mac_context *mac,
				    struct scheduler_msg *limMsgQ);

QDF_STATUS
rrm_process_neighbor_report_req(struct mac_context *mac,
				tpSirNeighborReportReqInd pNeighborReq);

QDF_STATUS
rrm_process_beacon_report_xmit(struct mac_context *mac_ctx,
			       tpSirBeaconReportXmitInd beacon_xmit_ind);

void lim_update_rrm_capability(struct mac_context *mac_ctx,
			       struct join_req *join_req);
#endif
