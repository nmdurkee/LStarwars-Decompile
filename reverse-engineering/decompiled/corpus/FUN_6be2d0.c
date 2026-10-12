/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6be2d0; label: FUN_006be2d0
 */

undefined4
FUN_006be2d0(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uStack_64;
  undefined1 local_54 [4];
  undefined1 local_50 [32];
  undefined4 auStack_30 [11];
  
  if ((in_ECX[7] & param_2) == 0) {
    return 0;
  }
  if (((param_2 & 8) == 0) || (in_ECX[3] != DAT_02973abc)) {
    if ((param_2 & 0x100) == 0) {
      uStack_64 = param_5;
      (**(code **)(*in_ECX + 4))(param_1,param_3,param_4);
      return 1;
    }
    uStack_64 = 0;
    (**(code **)(*in_ECX + 4))(param_1,DAT_02973aac,local_54);
    uVar2 = 2;
    puVar1 = &uStack_64;
  }
  else {
    uStack_64 = 0;
    (**(code **)(*in_ECX + 4))(param_1,DAT_02973abc,local_50);
    uVar2 = 0x10;
    puVar1 = auStack_30;
  }
  FUN_004ef660(param_4,puVar1,uVar2);
  return 1;
}

