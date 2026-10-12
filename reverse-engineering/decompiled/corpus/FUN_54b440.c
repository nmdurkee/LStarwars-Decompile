/* Ghidra analysis pseudocode, not original source.
 * ev_8596ba445ec28a67360d3f0861ead8a3280f05511d85e94c707c5f0d315a64a6
 * Entry: 0x54b440; label: FUN_0054b440
 */

undefined4 FUN_0054b440(void)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  iVar2 = FUN_0055f450();
  uVar3 = 0;
  bVar1 = false;
  iVar4 = 0;
  do {
    FUN_0054ae40(iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  DAT_00926bd0 = 0;
  if (iVar2 == 0) {
    if (DAT_0093b338 == 0) goto LAB_0054b4a8;
  }
  else if (*(int *)(iVar2 + 0x128) != DAT_00951b88) goto LAB_0054b4a8;
  iVar2 = FUN_006d9120(0,0x1a,local_4,local_8,1);
  if (-1 < iVar2) {
    bVar1 = true;
  }
LAB_0054b4a8:
  if ((((DAT_009253b4 & DAT_008022a0) != 0) || (bVar1)) || ((DAT_00925414 & DAT_008022a0) != 0)) {
    uVar3 = 1;
  }
  FUN_006d6b40();
  iVar2 = FUN_006d6c40(0x1c);
  if (((iVar2 == 0) && (iVar2 = FUN_006d6c40(0x39), iVar2 == 0)) &&
     (iVar2 = FUN_006d6c40(1), iVar2 == 0)) {
    return uVar3;
  }
  return 1;
}

