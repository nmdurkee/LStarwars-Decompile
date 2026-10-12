/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x6629f0; label: FUN_006629f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006629f0(void)

{
  int iVar1;
  undefined1 uVar2;
  
  if ((DAT_029231a8 != -1) && (iVar1 = (&DAT_02924b60)[DAT_029231a8 * 0x16], iVar1 != -1)) {
    uVar2 = FUN_006e6b90();
    *(undefined1 *)
     (*(int *)(DAT_0296209c + *(short *)(iVar1 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x411) = uVar2
    ;
  }
  return;
}

