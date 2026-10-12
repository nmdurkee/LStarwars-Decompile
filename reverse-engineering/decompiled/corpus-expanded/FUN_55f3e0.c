/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f3e0; label: FUN_0055f3e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055f3e0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  if (((param_1 != 0) && (*(int *)(in_ECX + 0x808) == 0)) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x70c))) {
    puVar1 = (undefined4 *)(in_ECX + 0x2b8);
    do {
      *puVar1 = puVar1[-1];
      puVar1[0x11] = puVar1[0x10];
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xe0;
    } while (iVar2 < *(int *)(in_ECX + 0x70c));
  }
  *(int *)(in_ECX + 0x808) = param_1;
  return;
}

