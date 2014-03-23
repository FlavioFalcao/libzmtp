/*  =========================================================================
    zmtp_channel - channel class

    Copyright (c) contributors as noted in the AUTHORS file.
    This file is part of libzmtp, the C ZMTP stack.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef __ZMTP_CHANNEL_H_INCLUDED__
#define __ZMTP_CHANNEL_H_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
typedef struct _zmtp_channel_t zmtp_channel_t;

//  @interface
//  Constructor
zmtp_channel_t *
    zmtp_channel_new ();

//  Destructor; closes fd if connected
void
    zmtp_channel_destroy (zmtp_channel_t **self_p);

//  Connect channel using local transport
int
    zmtp_channel_ipc_connect (zmtp_channel_t *self, const char *path);

//  Connect channel using TCP transport.
int
    zmtp_channel_tcp_connect (zmtp_channel_t *self,
                              const char *addr, unsigned short port);

//  Negotiate a ZMTP connection
//  This currently does only ZMTP v3, and will reject older protocols.
//  TODO: test sending random/wrong data to this handler.
int
    zmtp_channel_negotiate (zmtp_channel_t *self, int socktype);

//  Send a ZMTP message to the channel
int
    zmtp_channel_send (zmtp_channel_t *self, zmtp_msg_t *msg);

//  Receive a ZMTP message off the channel
zmtp_msg_t *
    zmtp_channel_recv (zmtp_channel_t *self);

//  Self test of this class
void
    zmtp_channel_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif