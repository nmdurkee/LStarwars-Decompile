/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x61a760; label: FUN_0061a760
 */

undefined4 *
FUN_0061a760(int param_1,float param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)
           FUN_004eef40(0x20,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xa37);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar3 = *(undefined4 **)(param_1 + 0x4c);
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    do {
      puVar2 = puVar3;
      puVar3 = puVar2;
      if (param_2 < (float)puVar2[2]) break;
      puVar3 = (undefined4 *)*puVar2;
      puVar4 = puVar2;
    } while (puVar3 != (undefined4 *)0x0);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = puVar1;
      goto LAB_0061a7c9;
    }
  }
  *(undefined4 **)(param_1 + 0x4c) = puVar1;
LAB_0061a7c9:
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[1] = puVar1;
  }
  puVar1[2] = param_2;
  puVar1[1] = puVar4;
  *puVar1 = puVar3;
  FUN_0061a670(puVar1,param_3,param_4,param_5);
  *(undefined4 **)(param_1 + 0x50) = puVar1;
  return puVar1;
}

