/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c1390; label: FUN_004c1390
 */

void FUN_004c1390(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *local_28;
  undefined1 local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_28;
  iVar4 = 0;
  iVar5 = 0;
  local_28 = &DAT_007f3dac;
  do {
    FUN_004f1f10(iVar5 + 0x40 + DAT_00880480,local_28[1]);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),iVar5 + 0x68 + DAT_00880480,
                 iVar5 + 0x40 + DAT_00880480,1);
    *(short *)(iVar5 + 0x60 + DAT_00880480) = (short)iVar4;
    *(undefined1 *)(iVar5 + 0x62 + DAT_00880480) = 2;
    iVar6 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
    *(undefined1 *)(iVar5 + 99 + DAT_00880480) = 0;
    uVar2 = __allshl();
    if ((uVar2 & (&DAT_0086e4b8)[iVar6]) != 0) {
      *(undefined1 *)(iVar5 + 99 + DAT_00880480) = 1;
      (&DAT_0086e4c8)[iVar6] = (&DAT_0086e4c8)[iVar6] | 1 << ((byte)iVar4 & 0x1f);
    }
    uVar1 = *local_28;
    local_28 = local_28 + 8;
    *(undefined4 *)(iVar5 + 100 + DAT_00880480) = uVar1;
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x74;
  } while ((int)local_28 < 0x7f432c);
  iVar4 = 0;
  DAT_0087bbc0 = 0x2c;
  iVar5 = 0;
  puVar3 = &DAT_0087c268;
  do {
    FUN_004f1f10(local_24,iVar5 + 0x40 + DAT_00880480);
    FUN_004f1e80(local_24,&DAT_00758b40);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),puVar3,local_24,1);
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x74;
    puVar3 = puVar3 + 0xc;
  } while (iVar4 < DAT_0087bbc0);
  __security_check_cookie(local_4 ^ (uint)&local_28);
  return;
}

