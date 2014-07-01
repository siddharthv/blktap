/*
 * Copyright (C) 2012      Citrix Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#ifndef __TD_STATS_H__
#define __TD_STATS_H__

struct td_xenblkif_stats {
    struct {
        unsigned long long in;
        unsigned long long out;
    } reqs;
    struct {
        unsigned long long in;
        unsigned long long out;
    } kicks;
    struct {
        unsigned long long msg;
        unsigned long long map;
        unsigned long long vbd;
        unsigned long long img;
    } errors;

    /**
     * blkback-style stats
     */
    struct {
        /**
         * BLKIF_OP_DISCARD, not currently supported in blktap3, should always
         * be zero
         */
        unsigned long long st_ds_req;

        /**
         * BLKIF_OP_FLUSH_DISKCACHE, not currently supported in blktap3,
         * should always be zero
         */
        unsigned long long st_f_req;

        /**
         * Increased each time we fail to allocate memory for a internal
         * request descriptor in response to a ring request.
         */
        unsigned long long st_oo_req;

        /**
         * Received BLKIF_OP_READ requests.
         */
        unsigned long long st_rd_req;

        /**
         * Completed BLKIF_OP_READ requests.
         */
        long long st_rd_cnt;

        /**
         * Read sectors, after we've forwarded the request to actual storage.
         */
        unsigned long long st_rd_sect;

        /**
         * Sum of the request response time of all BLKIF_OP_READ, in us.
         */
        long long st_rd_sum_usecs;

        /**
         * Absolute maximum BLKIF_OP_READ response time, in us.
         */
	    long long st_rd_max_usecs;

        /**
         * Received BLKIF_OP_WRITE requests.
         */
        unsigned long long st_wr_req;

        /**
         * Completed BLKIF_OP_WRITE requests.
         */
        long long st_wr_cnt;

        /**
         * Write sectors, after we've forwarded the request to actual storage.
         */
        unsigned long long st_wr_sect;

        /**
         * Sum of the request response time of all BLKIF_OP_WRITE, in us.
         */
        long long st_wr_sum_usecs;

        /**
         * Absolute maximum BLKIF_OP_WRITE response time, in us.
         */
	    long long st_wr_max_usecs;

    } xenvbd;
};

#include "td-blkif.h"
struct td_xenblkif;

void
tapdisk_xenblkif_stats(struct td_xenblkif * blkif, td_stats_t * st);

#endif /* __TD_STATS_H__ */
