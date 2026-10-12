/* Ghidra pseudocode, not original source.
 * ev_48ff0e80e492cdbcfd6e19b242aa934bd4f134661b9f943047c850011602a6eb
 * Entry: 0x6bc430; label: FUN_006bc430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bc430(uint param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = (undefined4 *)(in_ECX + 0x101c);
  do {
    if ((param_1 & 1 << ((byte)iVar1 & 0x1f)) != 0) {
      *puVar2 = param_2;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x20);
  return;
}

