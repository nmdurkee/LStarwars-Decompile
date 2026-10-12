/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e1070; label: FUN_005e1070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e1070(void)

{
  int iVar1;
  
  DAT_02854d1c = DAT_02854d1c + 1;
  FUN_00600b20(1);
  FUN_00607d70(0xd,7,0);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_006009e0(0xbf800000,0xbf800000,0);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  FUN_006009e0(0x3f800000,0xbf800000,0);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;
  FUN_006009e0(0xbf800000,0x3f800000,0);
  FUN_005c1f70();
  iVar1 = *DAT_02854d10;
  *(undefined4 *)(iVar1 + 0x10) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x14) = 0x3f800000;
  FUN_006009e0(0x3f800000,0x3f800000,0);
  FUN_006009a0();
  iVar1 = DAT_02854d1c * 4;
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar1));
  return;
}

