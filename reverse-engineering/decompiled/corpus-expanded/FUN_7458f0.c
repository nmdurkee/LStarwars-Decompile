/* Ghidra pseudocode, not original source.
 * ev_ac26ce749027d8ec0aff2eea20dc28ff8b92ba016e1d9b13f008953590b31814
 * Entry: 0x7458f0; label: FUN_007458f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007458f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int *piVar3;
  undefined4 uVar4;
  int local_4;
  
  local_4 = 0;
  FUN_007449f0(&local_4,param_1,param_2);
  iVar1 = 0;
  piVar3 = (int *)(in_ECX + 0xc);
  do {
    if (local_4 == *piVar3) {
      puVar2 = (undefined4 *)(iVar1 * 0x4d8 + 4 + in_ECX);
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = *puVar2;
        FUN_00744010(puVar2);
        goto LAB_00745946;
      }
      break;
    }
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 0x136;
  } while (iVar1 < 400);
  puVar2 = (undefined4 *)FUN_007414c0(&param_1);
  uVar4 = param_1;
LAB_00745946:
  FUN_00743da0(puVar2,&local_4,uVar4,param_3,param_4,param_5,param_6,
               *(undefined4 *)(*(int *)(in_ECX + 0x7918c) + 0xb80));
  return;
}

