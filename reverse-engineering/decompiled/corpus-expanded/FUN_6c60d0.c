/* Ghidra pseudocode, not original source.
 * ev_647b85ee0a7e8e41d889ce710347a98583a3d140d8a364c007ecae69f59044b8
 * Entry: 0x6c60d0; label: FUN_006c60d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c60d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(in_ECX + 0x14) + param_1);
  uVar1 = FUN_006c6010(param_2,param_4);
  if (puVar2 != (undefined4 *)0x0) {
    if ((*(uint *)(in_ECX + 0x1c) & 0x40000000) != 0) {
      puVar2 = (undefined4 *)*puVar2;
    }
    FUN_004ef660(puVar2,param_3,uVar1);
  }
  return;
}

