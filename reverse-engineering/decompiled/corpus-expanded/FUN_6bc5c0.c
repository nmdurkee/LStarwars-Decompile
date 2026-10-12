/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc5c0; label: FUN_006bc5c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc5c0(int param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  int iVar2;
  
  if (param_1 != 0) {
    FUN_004f1f10(in_ECX + 0x94c,param_1);
    iVar2 = in_ECX + 0x9cc;
    FUN_004f1f10(iVar2,in_ECX + 0x94c);
    puVar1 = (undefined1 *)FUN_004f1fc0(iVar2,0x2e);
    if (puVar1 != (undefined1 *)0x0) {
      *puVar1 = 0;
    }
    FUN_004f1e80(iVar2,PTR_DAT_0081f9b0);
    return;
  }
  *(undefined1 *)(in_ECX + 0x94c) = 0;
  *(undefined1 *)(in_ECX + 0x9cc) = 0;
  return;
}

