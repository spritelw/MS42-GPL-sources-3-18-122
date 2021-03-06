#ifndef _VTSS_LUTON26_REGS_DEVCPU_GCB_H_
#define _VTSS_LUTON26_REGS_DEVCPU_GCB_H_

/*
 *
 * VCore-III Register Definitions
 *
 * Copyright (C) 2010 Vitesse Semiconductor Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 * VITESSE SEMICONDUCTOR INC SHALL HAVE NO LIABILITY WHATSOEVER OF ANY
 * KIND ARISING OUT OF OR RELATED TO THE PROGRAM OR THE OPEN SOURCE
 * MATERIALS UNDER ANY THEORY OF LIABILITY.
 *
 */

#include "vtss_luton26_regs_common.h"

#define VTSS_DEVCPU_GCB_CHIP_REGS_GENERAL_PURPOSE  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x0)

#define VTSS_DEVCPU_GCB_CHIP_REGS_SI         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SI_SI_LSB  VTSS_BIT(5)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SI_SI_ENDIAN  VTSS_BIT(4)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_SI_SI_WAIT_STATES(x)  VTSS_ENCODE_BITFIELD(x,0,4)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_SI_SI_WAIT_STATES     VTSS_ENCODE_BITMASK(0,4)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_SI_SI_WAIT_STATES(x)  VTSS_EXTRACT_BITFIELD(x,0,4)

#define VTSS_DEVCPU_GCB_CHIP_REGS_CHIP_ID    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x2)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID(x)  VTSS_ENCODE_BITFIELD(x,28,4)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID     VTSS_ENCODE_BITMASK(28,4)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_REV_ID(x)  VTSS_EXTRACT_BITFIELD(x,28,4)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID(x)  VTSS_ENCODE_BITFIELD(x,12,16)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID     VTSS_ENCODE_BITMASK(12,16)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_PART_ID(x)  VTSS_EXTRACT_BITFIELD(x,12,16)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID(x)  VTSS_ENCODE_BITFIELD(x,1,11)
#define  VTSS_M_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID     VTSS_ENCODE_BITMASK(1,11)
#define  VTSS_X_DEVCPU_GCB_CHIP_REGS_CHIP_ID_MFG_ID(x)  VTSS_EXTRACT_BITFIELD(x,1,11)
#define  VTSS_F_DEVCPU_GCB_CHIP_REGS_CHIP_ID_ONE  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x5)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_IDENT(x)  VTSS_ENCODE_BITFIELD(x,8,8)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_IDENT     VTSS_ENCODE_BITMASK(8,8)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_IDENT(x)  VTSS_EXTRACT_BITFIELD(x,8,8)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_ENA(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_ENA     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SEMA_INTR_ENA(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_CLR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x6)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_CLR_SEMA_INTR_ENA_CLR(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_CLR_SEMA_INTR_ENA_CLR     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_CLR_SEMA_INTR_ENA_CLR(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SET  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SET_SEMA_INTR_ENA_SET(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SET_SEMA_INTR_ENA_SET     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SEMA_INTR_ENA_SET_SEMA_INTR_ENA_SET(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_DEVCPU_GCB_SW_REGS_SEMA(ri)     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8 + (ri))
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_SEMA  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_SW_REGS_SEMA_FREE    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x10)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SEMA_FREE_SEMA_FREE(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_SW_REGS_SEMA_FREE_SEMA_FREE     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_SW_REGS_SEMA_FREE_SEMA_FREE(x)  VTSS_EXTRACT_BITFIELD(x,0,8)

#define VTSS_DEVCPU_GCB_SW_REGS_SW_INTR      VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x11)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SW_INTR_SW1_INTR  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_SW_REGS_SW_INTR_SW0_INTR  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_SW_REGS_MAILBOX      VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x12)

#define VTSS_DEVCPU_GCB_SW_REGS_MAILBOX_CLR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x13)

#define VTSS_DEVCPU_GCB_SW_REGS_MAILBOX_SET  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x14)

#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x15)
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_ERR_RD  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_ERR  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY_RD  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_VCORE_ACCESS_VA_CTRL_VA_BUSY  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_ADDR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x16)

#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x17)

#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INCR  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x18)

#define VTSS_DEVCPU_GCB_VCORE_ACCESS_VA_DATA_INERT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x19)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_SET    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1a)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT_CLR    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1b)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_OUT        VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1c)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_IN         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1d)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_OE         VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1e)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR       VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x1f)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_ENA   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x20)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_INTR_IDENT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x21)

#define VTSS_DEVCPU_GCB_GPIO_GPIO_ALT(ri)    VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x22 + (ri))

#define VTSS_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_CHIP_RST  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x24)
#define  VTSS_F_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_CHIP_RST_SOFT_PHY_RST  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_CHIP_RST_SOFT_CHIP_RST  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_DEVCPU_RST  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x25)
#define  VTSS_F_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_DEVCPU_RST_SOFT_XTR_RST  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_DEVCPU_RST_REGS_SOFT_DEVCPU_RST_SOFT_INJ_RST  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MIIM_MII_STATUS(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,0)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_BUSY  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_OPR_PEND  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_RD  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_STAT_PENDING_WR  VTSS_BIT(0)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_STATUS_MIIM_SCAN_COMPLETE  VTSS_BIT(4)

#define VTSS_DEVCPU_GCB_MIIM_MII_CMD(gi)     VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,2)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_VLD  VTSS_BIT(31)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD(x)  VTSS_ENCODE_BITFIELD(x,25,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD     VTSS_ENCODE_BITMASK(25,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_PHYAD(x)  VTSS_EXTRACT_BITFIELD(x,25,5)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD(x)  VTSS_ENCODE_BITFIELD(x,20,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD     VTSS_ENCODE_BITMASK(20,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_REGAD(x)  VTSS_EXTRACT_BITFIELD(x,20,5)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA(x)  VTSS_ENCODE_BITFIELD(x,4,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA     VTSS_ENCODE_BITMASK(4,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_WRDATA(x)  VTSS_EXTRACT_BITFIELD(x,4,16)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SINGLE_SCAN  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD(x)  VTSS_ENCODE_BITFIELD(x,1,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD     VTSS_ENCODE_BITMASK(1,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_OPR_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,1,2)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CMD_MIIM_CMD_SCAN  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MIIM_MII_DATA(gi)    VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,3)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS(x)  VTSS_ENCODE_BITFIELD(x,16,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS     VTSS_ENCODE_BITMASK(16,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_SUCCESS(x)  VTSS_EXTRACT_BITFIELD(x,16,2)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_DATA_MIIM_DATA_RDDATA(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_DEVCPU_GCB_MIIM_MII_CFG(gi)     VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,4)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE(x)  VTSS_ENCODE_BITFIELD(x,0,8)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE     VTSS_ENCODE_BITMASK(0,8)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_MIIM_CFG_PRESCALE(x)  VTSS_EXTRACT_BITFIELD(x,0,8)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD(x)  VTSS_ENCODE_BITFIELD(x,9,2)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD     VTSS_ENCODE_BITMASK(9,2)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_CFG_MIIM_ST_CFG_FIELD(x)  VTSS_EXTRACT_BITFIELD(x,9,2)

#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_0(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,5)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI(x)  VTSS_ENCODE_BITFIELD(x,5,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI     VTSS_ENCODE_BITMASK(5,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADHI(x)  VTSS_EXTRACT_BITFIELD(x,5,5)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO(x)  VTSS_ENCODE_BITFIELD(x,0,5)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO     VTSS_ENCODE_BITMASK(0,5)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_0_MIIM_SCAN_PHYADLO(x)  VTSS_EXTRACT_BITFIELD(x,0,5)

#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_1(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,6)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK(x)  VTSS_ENCODE_BITFIELD(x,16,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK     VTSS_ENCODE_BITMASK(16,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_MASK(x)  VTSS_EXTRACT_BITFIELD(x,16,16)
#define  VTSS_F_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MIIM_MII_SCAN_1_MIIM_SCAN_EXPECT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,7)

#define VTSS_DEVCPU_GCB_MIIM_MII_SCAN_LAST_RSLTS_VLD(gi)  VTSS_IOREG_IX(VTSS_TO_DEVCPU_GCB,0x28,gi,9,0,8)

#define VTSS_DEVCPU_GCB_MIIM_READ_SCAN_MII_SCAN_RSLTS_STICKY(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3a + (ri))

#define VTSS_DEVCPU_GCB_FEATURES_FEA_STAT(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x3c + (ri))

#define VTSS_DEVCPU_GCB_RAM_STAT_RAM_INTEGRITY_ERR_STICKY  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x45)
#define  VTSS_F_DEVCPU_GCB_RAM_STAT_RAM_INTEGRITY_ERR_STICKY_QS_XTR_RAM_INTGR_ERR_STICKY  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MISC_MISC_CFG        VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x46)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_SYNCE_SRC_CTRL(x)  VTSS_ENCODE_BITFIELD(x,8,2)
#define  VTSS_M_DEVCPU_GCB_MISC_MISC_CFG_SYNCE_SRC_CTRL     VTSS_ENCODE_BITMASK(8,2)
#define  VTSS_X_DEVCPU_GCB_MISC_MISC_CFG_SYNCE_SRC_CTRL(x)  VTSS_EXTRACT_BITFIELD(x,8,2)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_SW_MODE(x)  VTSS_ENCODE_BITFIELD(x,6,2)
#define  VTSS_M_DEVCPU_GCB_MISC_MISC_CFG_SW_MODE     VTSS_ENCODE_BITMASK(6,2)
#define  VTSS_X_DEVCPU_GCB_MISC_MISC_CFG_SW_MODE(x)  VTSS_EXTRACT_BITFIELD(x,6,2)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_FLIP_LANE1  VTSS_BIT(5)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_FLIP_LANE2  VTSS_BIT(4)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_FLIP_LANE3  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_SHYST_DIS  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_E_DET_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_CFG_QSGMII_USE_I1_ENA  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MISC_MISC_STAT       VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x47)
#define  VTSS_F_DEVCPU_GCB_MISC_MISC_STAT_PHY_READY  VTSS_BIT(3)

#define VTSS_DEVCPU_GCB_MISC_PHY_SPEED_1000_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x48)
#define  VTSS_F_DEVCPU_GCB_MISC_PHY_SPEED_1000_STAT_SPEED_1000(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_MISC_PHY_SPEED_1000_STAT_SPEED_1000     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_MISC_PHY_SPEED_1000_STAT_SPEED_1000(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_MISC_PHY_SPEED_100_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x49)
#define  VTSS_F_DEVCPU_GCB_MISC_PHY_SPEED_100_STAT_SPEED_100(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_MISC_PHY_SPEED_100_STAT_SPEED_100     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_MISC_PHY_SPEED_100_STAT_SPEED_100(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_MISC_PHY_SPEED_10_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x4a)
#define  VTSS_F_DEVCPU_GCB_MISC_PHY_SPEED_10_STAT_SPEED_10(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_MISC_PHY_SPEED_10_STAT_SPEED_10     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_MISC_PHY_SPEED_10_STAT_SPEED_10(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_MISC_DUPLEXC_PORT_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x4b)
#define  VTSS_F_DEVCPU_GCB_MISC_DUPLEXC_PORT_STAT_DUPLEXC(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_MISC_DUPLEXC_PORT_STAT_DUPLEXC     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_MISC_DUPLEXC_PORT_STAT_DUPLEXC(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INPUT_DATA(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x4c + (ri))

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INT_POL(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x50 + (ri))

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_INT_ENA  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x54)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CONFIG(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x55 + (ri))
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CONFIG_BIT_SOURCE(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CONFIG_BIT_SOURCE     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_PORT_CONFIG_BIT_SOURCE(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_PORT_ENABLE  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x75)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x76)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_1(x)  VTSS_ENCODE_BITFIELD(x,20,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_1     VTSS_ENCODE_BITMASK(20,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_1(x)  VTSS_EXTRACT_BITFIELD(x,20,2)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_0(x)  VTSS_ENCODE_BITFIELD(x,18,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_0     VTSS_ENCODE_BITMASK(18,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BMODE_0(x)  VTSS_EXTRACT_BITFIELD(x,18,2)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BLINK_RESET  VTSS_BIT(17)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_INT_ENA(x)  VTSS_ENCODE_BITFIELD(x,13,4)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_INT_ENA     VTSS_ENCODE_BITMASK(13,4)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_INT_ENA(x)  VTSS_EXTRACT_BITFIELD(x,13,4)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BURST_GAP_DIS  VTSS_BIT(12)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BURST_GAP(x)  VTSS_ENCODE_BITFIELD(x,7,5)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BURST_GAP     VTSS_ENCODE_BITMASK(7,5)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_BURST_GAP(x)  VTSS_EXTRACT_BITFIELD(x,7,5)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_SINGLE_SHOT  VTSS_BIT(6)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_AUTO_REPEAT  VTSS_BIT(5)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_LD_POLARITY  VTSS_BIT(4)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_PORT_WIDTH(x)  VTSS_ENCODE_BITFIELD(x,2,2)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_PORT_WIDTH     VTSS_ENCODE_BITMASK(2,2)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_PORT_WIDTH(x)  VTSS_EXTRACT_BITFIELD(x,2,2)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_REVERSE_OUTPUT  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CONFIG_SIO_REVERSE_INPUT  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK   VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x77)
#define  VTSS_F_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ(x)  VTSS_ENCODE_BITFIELD(x,0,12)
#define  VTSS_M_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ     VTSS_ENCODE_BITMASK(0,12)
#define  VTSS_X_DEVCPU_GCB_SIO_CTRL_SIO_CLOCK_SIO_CLK_FREQ(x)  VTSS_EXTRACT_BITFIELD(x,0,12)

#define VTSS_DEVCPU_GCB_SIO_CTRL_SIO_INT_REG(ri)  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x78 + (ri))

#define VTSS_DEVCPU_GCB_FAN_CFG_FAN_CFG      VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7c)
#define  VTSS_F_DEVCPU_GCB_FAN_CFG_FAN_CFG_PWM_FREQ(x)  VTSS_ENCODE_BITFIELD(x,3,3)
#define  VTSS_M_DEVCPU_GCB_FAN_CFG_FAN_CFG_PWM_FREQ     VTSS_ENCODE_BITMASK(3,3)
#define  VTSS_X_DEVCPU_GCB_FAN_CFG_FAN_CFG_PWM_FREQ(x)  VTSS_EXTRACT_BITFIELD(x,3,3)
#define  VTSS_F_DEVCPU_GCB_FAN_CFG_FAN_CFG_INV_POL  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_FAN_CFG_FAN_CFG_GATE_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_FAN_CFG_FAN_CFG_PWM_OPEN_COL_ENA  VTSS_BIT(0)
#define  VTSS_F_DEVCPU_GCB_FAN_CFG_FAN_CFG_DUTY_CYCLE(x)  VTSS_ENCODE_BITFIELD(x,16,8)
#define  VTSS_M_DEVCPU_GCB_FAN_CFG_FAN_CFG_DUTY_CYCLE     VTSS_ENCODE_BITMASK(16,8)
#define  VTSS_X_DEVCPU_GCB_FAN_CFG_FAN_CFG_DUTY_CYCLE(x)  VTSS_EXTRACT_BITFIELD(x,16,8)

#define VTSS_DEVCPU_GCB_FAN_STAT_FAN_CNT     VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7d)
#define  VTSS_F_DEVCPU_GCB_FAN_STAT_FAN_CNT_FAN_CNT(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_FAN_STAT_FAN_CNT_FAN_CNT     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_FAN_STAT_FAN_CNT_FAN_CNT(x)  VTSS_EXTRACT_BITFIELD(x,0,16)

#define VTSS_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7e)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_OUTP_SEL  VTSS_BIT(7)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_OUTP_INV  VTSS_BIT(6)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_OUTP_ENA  VTSS_BIT(5)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_INP_SEL  VTSS_BIT(4)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_INP_INV  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_INP_ENA  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_EXT_SYNC_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_MISC_CFG_PTP_ENA  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x7f)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_CFG_PTP_UPPER_LIMIT(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_CFG_PTP_UPPER_LIMIT     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_CFG_PTP_UPPER_LIMIT(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x80)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_SHOT  VTSS_BIT(31)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ_CFG_PTP_UPPER_LIMIT_1_TIME_ADJ(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_CFG_PTP_SYNC_INTR_ENA_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x81)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_SYNC_INTR_ENA_CFG_EXT_SYNC_CURRENT_TIME_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_PTP_SYNC_INTR_ENA_CFG_SYNC_STAT_ENA  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_HIGH_PERIOD_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x82)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_HIGH_PERIOD_CFG_GEN_EXT_CLK_HIGH_PERIOD(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_HIGH_PERIOD_CFG_GEN_EXT_CLK_HIGH_PERIOD     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_HIGH_PERIOD_CFG_GEN_EXT_CLK_HIGH_PERIOD(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_LOW_PERIOD_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x83)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_LOW_PERIOD_CFG_GEN_EXT_CLK_LOW_PERIOD(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_LOW_PERIOD_CFG_GEN_EXT_CLK_LOW_PERIOD     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_LOW_PERIOD_CFG_GEN_EXT_CLK_LOW_PERIOD(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x84)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_CFG_GEN_EXT_CLK_SYNC_ENA  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_CFG_GEN_EXT_CLK_ADJ_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_GEN_EXT_CLK_CFG_GEN_EXT_CLK_ENA  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x85)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_DIR  VTSS_BIT(31)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_ENA  VTSS_BIT(30)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ_UPD  VTSS_BIT(29)
#define  VTSS_F_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_CFG_CLK_ADJ_CFG_CLK_ADJ(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_STAT_PTP_CURRENT_TIME_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x86)
#define  VTSS_F_DEVCPU_GCB_PTP_STAT_PTP_CURRENT_TIME_STAT_PTP_CURRENT_TIME(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_STAT_PTP_CURRENT_TIME_STAT_PTP_CURRENT_TIME     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_STAT_PTP_CURRENT_TIME_STAT_PTP_CURRENT_TIME(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_STAT_EXT_SYNC_CURRENT_TIME_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x87)
#define  VTSS_F_DEVCPU_GCB_PTP_STAT_EXT_SYNC_CURRENT_TIME_STAT_EXT_SYNC_CURRENT_TIME(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_STAT_EXT_SYNC_CURRENT_TIME_STAT_EXT_SYNC_CURRENT_TIME     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_STAT_EXT_SYNC_CURRENT_TIME_STAT_EXT_SYNC_CURRENT_TIME(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_STAT_PTP_EVT_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x88)
#define  VTSS_F_DEVCPU_GCB_PTP_STAT_PTP_EVT_STAT_CLK_ADJ_UPD_STICKY  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_PTP_STAT_PTP_EVT_STAT_EXT_SYNC_CURRENT_TIME_STICKY  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_PTP_STAT_PTP_EVT_STAT_SYNC_STAT  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_PTP_TIMERS_PTP_TOD_SECS  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x89)

#define VTSS_DEVCPU_GCB_PTP_TIMERS_PTP_TOD_NANOSECS  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8a)
#define  VTSS_F_DEVCPU_GCB_PTP_TIMERS_PTP_TOD_NANOSECS_PTP_TOD_NANOSECS(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_PTP_TIMERS_PTP_TOD_NANOSECS_PTP_TOD_NANOSECS     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_PTP_TIMERS_PTP_TOD_NANOSECS_PTP_TOD_NANOSECS(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_PTP_TIMERS_PTP_DELAY  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8b)

#define VTSS_DEVCPU_GCB_PTP_TIMERS_PTP_TIMER_CTRL  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8c)
#define  VTSS_F_DEVCPU_GCB_PTP_TIMERS_PTP_TIMER_CTRL_PTP_LATCH  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_PTP_TIMERS_PTP_TIMER_CTRL_PTP_TIMER_ENA  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_PTP_TIMERS_PTP_TIMER_CTRL_PTP_TOD_RST  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8d)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_CTRL_ACTIVATE  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_STAT  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8e)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_INDICATION  VTSS_BIT(4)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_LISTEN  VTSS_BIT(3)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_DETECT  VTSS_BIT(2)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_IDLE  VTSS_BIT(1)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_STAT_MODE_BUSY  VTSS_BIT(0)

#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_INFO  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x8f)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR  VTSS_BIT(31)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR  VTSS_BIT(30)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ERR_OVF  VTSS_BIT(29)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_COR_OVF  VTSS_BIT(28)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR(x)  VTSS_ENCODE_BITFIELD(x,0,28)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR     VTSS_ENCODE_BITMASK(0,28)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_INFO_MEM_ADDR(x)  VTSS_EXTRACT_BITFIELD(x,0,28)

#define VTSS_DEVCPU_GCB_MEMITGR_MEMITGR_IDX  VTSS_IOREG(VTSS_TO_DEVCPU_GCB,0x90)
#define  VTSS_F_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX(x)  VTSS_ENCODE_BITFIELD(x,0,16)
#define  VTSS_M_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX     VTSS_ENCODE_BITMASK(0,16)
#define  VTSS_X_DEVCPU_GCB_MEMITGR_MEMITGR_IDX_MEM_IDX(x)  VTSS_EXTRACT_BITFIELD(x,0,16)


#endif /* _VTSS_LUTON26_REGS_DEVCPU_GCB_H_ */
