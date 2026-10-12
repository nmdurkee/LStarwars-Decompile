/* Ghidra analysis pseudocode, not original source.
 * ev_528f0eafdf60551b868e0e925a842777892bdaf44669a30da4d03ef81027d70b
 * Entry: 0x6ddec0; label: FUN_006ddec0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ddec0(void)

{
  undefined4 *puVar1;
  
  if (_DAT_00827638 == -1) {
    puVar1 = (undefined4 *)FUN_004eef40(0x28,".\\windows.cpp",0x642);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[9] = 0;
    puVar1[7] = s_DDS___00826590;
    puVar1[8] = 0x1080;
    _DAT_00827638 = FUN_005e5210(puVar1);
  }
  DAT_02975c48 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_02975c48 + 0x54) = 0x3f800000;
  *(undefined4 *)(DAT_02975c48 + 0x58) = 0x3f800000;
  *(undefined4 *)(DAT_02975c48 + 0x5c) = 0x3f800000;
  *(uint *)(DAT_02975c48 + 0x40) = *(uint *)(DAT_02975c48 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_02975c48 + 0x40) = *(uint *)(DAT_02975c48 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_02975c48 + 0x70) = 0x3f800000;
  *(uint *)(DAT_02975c48 + 0x40) = *(uint *)(DAT_02975c48 + 0x40) & 0xfffffff1 | 1;
  *(uint *)(DAT_02975c48 + 0x40) = *(uint *)(DAT_02975c48 + 0x40) | 0x40000;
  *(undefined2 *)(DAT_02975c48 + 0x74) = DAT_00827638;
  FUN_005e4b00(DAT_02975c48);
  return;
}

