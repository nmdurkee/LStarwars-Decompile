/* Ghidra pseudocode, not original source.
 * ev_55c731fbd74135d460c444c417a3a15a2648f8ead34d22c2fd0b5dd9a411012b
 * Entry: 0x421020; label: FUN_00421020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00421020(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  puVar1 = (undefined4 *)(in_ECX + 0x1f8);
  iVar2 = 0xc;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x4a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

