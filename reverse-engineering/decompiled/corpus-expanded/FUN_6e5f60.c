/* Ghidra pseudocode, not original source.
 * ev_22c329bac68cac2fc7bcf67b722cf469408ea6fe3402124ef456f33d7f316bc5
 * Entry: 0x6e5f60; label: FUN_006e5f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006e6230) */
/* WARNING: Removing unreachable block (ram,0x006e6220) */
/* WARNING: Removing unreachable block (ram,0x006e626b) */
/* WARNING: Removing unreachable block (ram,0x006e6250) */
/* WARNING: Removing unreachable block (ram,0x006e608d) */
/* WARNING: Removing unreachable block (ram,0x006e5ff0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_006e5f60(void)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int *unaff_FS_OFFSET;
  byte in_AF;
  byte in_TF;
  byte in_IF;
  byte in_NT;
  byte in_AC;
  byte in_VIF;
  byte in_VIP;
  byte in_ID;
  uint uVar5;
  undefined1 local_14 [16];
  
  iVar1 = *unaff_FS_OFFSET;
  uVar4 = DAT_00829570 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)local_14;
  uVar5 = (uint)(in_NT & 1) * 0x4000 | (uint)(in_IF & 1) * 0x200 | (uint)(in_TF & 1) * 0x100 |
          (uint)((int)uVar4 < 0) * 0x80 | (uint)(uVar4 == 0) * 0x40 | (uint)(in_AF & 1) * 0x10 |
          (uint)((POPCOUNT(uVar4 & 0xff) & 1U) == 0) * 4 | (uint)(in_ID & 1) * 0x200000 |
          (uint)(in_VIP & 1) * 0x100000 | (uint)(in_VIF & 1) * 0x80000 | (uint)(in_AC & 1) * 0x40000
  ;
  uVar4 = uVar5 ^ 0x200000;
  if (((uint)((uVar4 & 0x4000) != 0) * 0x4000 | (uint)((uVar4 & 0x200) != 0) * 0x200 |
       (uint)((uVar4 & 0x100) != 0) * 0x100 | (uint)((uVar4 & 0x80) != 0) * 0x80 |
       (uint)((uVar4 & 0x40) != 0) * 0x40 | (uint)((uVar4 & 0x10) != 0) * 0x10 |
       (uint)((uVar4 & 4) != 0) * 4 | (uint)((uVar4 & 0x200000) != 0) * 0x200000 |
      (uint)((uVar4 & 0x40000) != 0) * 0x40000) == uVar5) {
    DAT_0297c0e4 = 0;
    DAT_0297c0e8 = 0;
    DAT_008283b0 = s___No_CPUID___008283c0[0];
    DAT_008283b0_1._0_1_ = s___No_CPUID___008283c0[1];
    DAT_008283b0_1._1_1_ = s___No_CPUID___008283c0[2];
    DAT_008283b0_1._2_1_ = s___No_CPUID___008283c0[3];
    DAT_008283b4 = s___No_CPUID___008283c0[4];
    DAT_008283b4_1._0_1_ = s___No_CPUID___008283c0[5];
    DAT_008283b4_1._1_1_ = s___No_CPUID___008283c0[6];
    DAT_008283b4_1._2_1_ = s___No_CPUID___008283c0[7];
    DAT_008283b8 = s___No_CPUID___008283c0[8];
    DAT_008283b8_1._0_1_ = s___No_CPUID___008283c0[9];
    DAT_008283b8_1._1_1_ = s___No_CPUID___008283c0[10];
    DAT_008283b8_1._2_1_ = s___No_CPUID___008283c0[0xb];
    uVar4 = 0;
    uVar5 = s___No_CPUID___008283c0._4_4_;
  }
  else {
    DAT_0297c0e4 = 1;
    piVar2 = (int *)cpuid_basic_info(0);
    DAT_0297c0e8 = *piVar2;
    _DAT_008283b0 = piVar2[1];
    _DAT_008283b4 = piVar2[2];
    _DAT_008283b8 = piVar2[3];
    if (((_DAT_008283b0 == s_GenuineIntel_008283d0._0_4_) &&
        (_DAT_008283b4 == s_GenuineIntel_008283d0._4_4_)) &&
       (_DAT_008283b8 == s_GenuineIntel_008283d0._8_4_)) {
      DAT_0297c0c8 = 1;
    }
    else if (((_DAT_008283b0 == s__AuthenticAMD_0082838f._1_4_) &&
             (_DAT_008283b4 == s__AuthenticAMD_0082838f._5_4_)) &&
            (_DAT_008283b8 == s__AuthenticAMD_0082838f._9_4_)) {
      DAT_0297c0c8 = 2;
    }
    else if (((_DAT_008283b0 == s_CyrixInstead_008283a0._0_4_) &&
             (_DAT_008283b4 == s_CyrixInstead_008283a0._4_4_)) &&
            (_DAT_008283b8 == s_CyrixInstead_008283a0._8_4_)) {
      DAT_0297c0c8 = 3;
    }
    else {
      DAT_0297c0c8 = 0;
    }
    uVar4 = 0;
    uVar5 = _DAT_008283b4;
    if (DAT_0297c0e8 != 0) {
      puVar3 = (uint *)cpuid_Version_info(1);
      uVar4 = *puVar3;
      uVar5 = puVar3[2];
      DAT_0297c0ec = (uVar4 & 0x3000) >> 0xc;
      DAT_0297c0f0 = (uVar4 & 0xf00) >> 8;
      DAT_0297c0f4 = (uVar4 & 0xf0) >> 4;
      DAT_0297c0f8 = uVar4 & 0xf;
      DAT_0297c0fc = (undefined1)puVar3[1];
      DAT_0297c108 = (uVar5 & 2) >> 1;
      DAT_0297c104 = uVar5 & 1;
      DAT_0297c10c = (uVar5 & 4) >> 2;
      DAT_0297c110 = (uVar5 & 8) >> 3;
      DAT_0297c114 = (uVar5 & 0x10) >> 4;
      DAT_0297c118 = (uVar5 & 0x20) >> 5;
      DAT_0297c11c = (uVar5 & 0x40) >> 6;
      DAT_0297c120 = (uVar5 & 0x80) >> 7;
      DAT_0297c124 = (uVar5 & 0x100) >> 8;
      DAT_0297c128 = (uVar5 & 0x200) >> 9;
      DAT_0297c12c = (uVar5 & 0x1000) >> 0xc;
      DAT_0297c130 = (uVar5 & 0x2000) >> 0xd;
      DAT_0297c134 = (uVar5 & 0x4000) >> 0xe;
      DAT_0297c138 = (uVar5 & 0x8000) >> 0xf;
      DAT_0297c13c = (uVar5 & 0x800000) >> 0x17;
      uVar4 = DAT_0297c0c8;
      if (DAT_0297c0c8 == 1) {
        DAT_0297c0d0 = (uVar5 & 0x2000000) >> 0x19;
        DAT_0297c0d4 = (uVar5 & 0x4000000) >> 0x1a;
      }
      else if (DAT_0297c0c8 == 2) {
        DAT_0297c0d0 = (uVar5 & 0x2000000) >> 0x19;
        puVar3 = (uint *)cpuid(0x80000000);
        DAT_0297c0d8 = *puVar3;
        uVar5 = puVar3[2];
        uVar4 = 0;
        if (DAT_0297c0d8 != 0) {
          puVar3 = (uint *)cpuid(0x80000001);
          uVar5 = puVar3[2];
          DAT_0297c0cc = uVar5 >> 0x1f;
          uVar4 = *puVar3;
          _DAT_0297c0dc = uVar5;
        }
      }
      else if (DAT_0297c0c8 == 3) {
        puVar3 = (uint *)cpuid(0x80000000);
        DAT_0297c0d8 = *puVar3;
        uVar5 = puVar3[2];
        uVar4 = DAT_0297c0d8;
        if ((-0x80000000 <= (int)DAT_0297c0d8) && (uVar4 = 0x80000001, 0x80000000 < DAT_0297c0d8)) {
          puVar3 = (uint *)cpuid(0x80000001);
          uVar5 = puVar3[2];
          uVar4 = *puVar3;
          _DAT_0297c0dc = uVar5;
        }
      }
    }
  }
  DAT_0297c170 = 1;
  *unaff_FS_OFFSET = iVar1;
  return CONCAT44(uVar5,uVar4);
}

