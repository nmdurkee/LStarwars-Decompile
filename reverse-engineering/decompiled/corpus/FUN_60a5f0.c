/* Ghidra analysis pseudocode, not original source.
 * ev_2e9599a270e7c228276daed06211bb9a628229b53b154c3c2f5580fc0ff0e4f1
 * Entry: 0x60a5f0; label: FUN_0060a5f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060a5f0(byte param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  _memset(&DAT_02855358,0,0x1480);
  _DAT_028490b0 = 0;
  _DAT_028490b4 = 0;
  _DAT_028490b8 = 0;
  _DAT_028490bc = 0;
  _DAT_028490c0 = 0;
  _DAT_028490c4 = 0;
  _DAT_028490c8 = 0;
  _DAT_028490cc = 0;
  DAT_02854bc4 = 0;
  DAT_02854bc8 = 0;
  DAT_02854bcc = 0;
  if ((DAT_029766c0 < 2) || (bVar1 = true, (param_1 & 2) == 0)) {
    bVar1 = false;
  }
  if ((DAT_029766c0 < 2) || (bVar2 = true, (param_1 & 4) == 0)) {
    bVar2 = false;
  }
  iVar3 = FUN_00605a10();
  DAT_02854bc8 = iVar3;
  FUN_005fb870(DAT_02976c7c,0,0);
  iVar4 = DAT_02854bc8;
  *(undefined4 *)(iVar3 + 0xa0) = 1;
  *(undefined4 *)(iVar4 + 0x8c) = 0;
  FUN_005fb870(DAT_02976c84,0,0);
  iVar3 = DAT_02854bc8;
  *(undefined4 *)(iVar4 + 0xa0) = 1;
  *(undefined4 *)(iVar3 + 0x94) = 0xffffffff;
  iVar4 = iVar3;
  if ((bVar1) && (1 < DAT_02976cac)) {
    FUN_005fb870(DAT_02976c80,0,0);
    iVar4 = DAT_02854bc8;
    *(undefined4 *)(iVar3 + 0xa0) = 1;
    *(undefined **)(iVar4 + 0x90) = &DAT_00808080;
  }
  if ((bVar2) && (2 < DAT_02976cac)) {
    FUN_005fb870(DAT_02976c84,0,0);
    iVar3 = DAT_02854bc8;
    *(undefined4 *)(iVar4 + 0xa0) = 1;
    *(undefined4 *)(iVar3 + 0x94) = 0x8080;
  }
  iVar4 = FUN_00605a10();
  DAT_02854bcc = iVar4;
  FUN_005fb870(DAT_02976c7c,0,0);
  DAT_028492f4 = DAT_02854bcc;
  *(undefined4 *)(iVar4 + 0xa0) = 1;
  *(undefined4 *)(DAT_028492f4 + 0x8c) = 0;
  _DAT_028492f0 = DAT_02854bc8;
  FUN_005f8bf0(DAT_02854bc8);
  return;
}

