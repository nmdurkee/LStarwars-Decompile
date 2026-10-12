/* Ghidra pseudocode, not original source.
 * ev_2dc15e7d3c3d1805147447414f3f14c0abe3c311ca5fc4e615c2e0419915bb96
 * Entry: 0x5c51c0; label: FUN_005c51c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c51c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  
  puVar3 = in_ECX;
  do {
    puVar1 = in_ECX;
    if (in_ECX + 0xa00 <= puVar3) {
      while( true ) {
        puVar3 = puVar1;
        if (in_ECX + 0xa00 <= puVar3) {
          return -1;
        }
        if (puVar3[9] == 0) break;
        puVar1 = puVar3 + 10;
      }
      iVar2 = FUN_004f1ff0(param_1);
      FUN_004ef660(puVar3 + 1,param_1,iVar2 + 1);
      *puVar3 = param_2;
      puVar3[9] = puVar3[9] + 1;
LAB_005c5211:
      return ((int)puVar3 - (int)in_ECX) / 0x28;
    }
    iVar2 = FUN_004f20f0(puVar3 + 1,param_1);
    if (iVar2 == 0) {
      *puVar3 = param_2;
      goto LAB_005c5211;
    }
    puVar3 = puVar3 + 10;
  } while( true );
}

