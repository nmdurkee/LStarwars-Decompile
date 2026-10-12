/* Ghidra pseudocode, not original source.
 * ev_f4a8ff6582840101146b6beddb128c7f08992de8be10658b05520190150ad97a
 * Entry: 0x584a70; label: FUN_00584a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00584a70(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  *unaff_ESI = 0;
  iVar1 = FUN_004f7fb0(param_1);
  while (iVar1 != 0) {
    uVar2 = FUN_004f29a0(*(undefined4 *)(param_1 + 0x510));
    if (uVar2 < 0x20) {
      *unaff_ESI = *unaff_ESI | 1 << ((byte)uVar2 & 0x1f);
      iVar3 = iVar3 + 1;
    }
    iVar1 = FUN_004f7fb0(param_1);
  }
  return iVar3;
}

