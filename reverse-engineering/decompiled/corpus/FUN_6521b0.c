/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x6521b0; label: FUN_006521b0
 */

void FUN_006521b0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *puVar4;
  undefined4 *puVar5;
  int local_4;
  
  puVar4 = param_1;
  DAT_0292fda0 = *param_1 + 3 & 0xfffffffc;
  *param_1 = DAT_0292fda0;
  *param_1 = *param_1 + 0x200;
  DAT_02947d70 = (void *)(*param_1 + 3 & 0xfffffffc);
  *param_1 = (*param_1 + 3 & 0xfffffffc) + 0xaf00;
  iVar2 = 0;
  _memset(DAT_02947d70,0,0xaf00);
  DAT_02947b74 = (void *)(*param_1 + 3 & 0xfffffffc);
  *param_1 = (*param_1 + 3 & 0xfffffffc) + 0x19000;
  _memset(DAT_02947b74,0,0x19000);
  DAT_0292fda4 = (void *)(*param_1 + 3 & 0xfffffffc);
  *param_1 = (*param_1 + 3 & 0xfffffffc) + 0x19000;
  _memset(DAT_0292fda4,0,0x19000);
  FUN_00650280(param_1,param_2);
  iVar1 = 0;
  do {
    *(undefined2 *)(iVar1 + DAT_0292fda0) = 0xffff;
    iVar1 = iVar1 + 2;
  } while (iVar1 < 0x200);
  iVar1 = 0;
  DAT_02962014 = 0;
  DAT_0296201c = 0;
  local_4 = 0;
  if (0 < DAT_0296202c) {
    param_1 = (uint *)&DAT_02948f10;
    do {
      puVar3 = (undefined4 *)(DAT_02962028 + iVar2);
      puVar5 = (undefined4 *)((int)DAT_02947d70 + iVar2);
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar5 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar5 = puVar5 + 1;
      }
      *(int *)((int)DAT_02947d70 + iVar2 + 0xc) = local_4;
      FUN_004f1f10(param_1,*(undefined4 *)((int)DAT_02947d70 + iVar2));
      DAT_02962014 = DAT_02962014 + 1;
      DAT_02962018 = DAT_02962018 + 1;
      *(uint **)((int)DAT_02947d70 + iVar2) = param_1;
      iVar1 = local_4 + 1;
      param_1 = (uint *)((int)param_1 + 0x40);
      iVar2 = iVar2 + 0x1c;
      local_4 = iVar1;
    } while (iVar1 < DAT_0296202c);
  }
  iVar1 = iVar1 * 0x1c;
  *(undefined4 *)(iVar1 + (int)DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 4 + (int)DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 8 + (int)DAT_02947d70) = 0;
  *(undefined4 *)(iVar1 + 0xc + (int)DAT_02947d70) = 0xffffffff;
  FUN_004f1f10(s_U_Audio_audio_cfg_00810366 + 2,param_3);
  FUN_006520b0(param_3,puVar4,param_2);
  _memset(&DAT_02947ca8,0,200);
  if (0 < DAT_0296201c) {
    puVar4 = (uint *)((int)DAT_02947b74 + 4);
    iVar1 = DAT_0296201c;
    do {
      if ((*puVar4 & 0x20000) != 0) {
        iVar2 = *puVar4 << 0x11;
        *(ushort *)(&DAT_02947ca8 + (iVar2 >> 0x15) * 2) =
             *(ushort *)(&DAT_02947ca8 + (iVar2 >> 0x15) * 2) |
             (ushort)(1 << ((byte)(iVar2 >> 0x11) & 0xf));
      }
      puVar4 = puVar4 + 0x10;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  FUN_004ef660();
  return;
}

