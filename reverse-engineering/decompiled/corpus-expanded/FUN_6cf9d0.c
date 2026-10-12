/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf9d0; label: FUN_006cf9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf9d0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 uVar6;
  int in_ECX;
  int unaff_ESI;
  undefined4 unaff_EDI;
  
  puVar3 = (undefined4 *)FUN_00633440(0x14,1);
  piVar2 = param_2;
  if (puVar3 != (undefined4 *)0x0) {
    puVar3[4] = *(undefined4 *)(in_ECX + 0x10);
    *puVar3 = &PTR_FUN_0076b64c;
    puVar3[2] = param_2;
    puVar3[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973ab0,&param_2,0);
    piVar4 = *(int **)(in_ECX + 0x10);
    iVar1 = *piVar4;
    while (iVar1 != 0) {
      if (piVar4[1] == unaff_ESI) {
        pcVar5 = (char *)*piVar4;
        goto LAB_006cfa42;
      }
      piVar4 = piVar4 + 2;
      iVar1 = *piVar4;
    }
    pcVar5 = "Unknown";
LAB_006cfa42:
    uVar6 = FUN_00626250(puVar3,&DAT_0081f9a0,FUN_006cf8e0,FUN_006b9ec0,&LAB_006c3e10,1,piVar2[4],
                         pcVar5);
    puVar3[1] = uVar6;
    FUN_00618e10(unaff_EDI,uVar6);
  }
  return;
}

