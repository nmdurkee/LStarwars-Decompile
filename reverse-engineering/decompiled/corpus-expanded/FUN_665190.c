/* Ghidra pseudocode, not original source.
 * ev_1085323f9a3cb798a23dfec0c4468a06f744be49385e8c8d18d4e2ca61b2546b
 * Entry: 0x665190; label: FUN_00665190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00665190(void)

{
  int iVar1;
  undefined1 uVar2;
  
  if ((DAT_029231a8 != -1) && (iVar1 = (&DAT_02924b60)[DAT_029231a8 * 0x16], iVar1 != -1)) {
    uVar2 = FUN_006e6b90();
    *(undefined1 *)
     (*(int *)(DAT_0296209c + *(short *)(iVar1 * 0x330 + 0x182 + DAT_029620a4) * 4) + 0x2f0) = uVar2
    ;
  }
  return;
}

