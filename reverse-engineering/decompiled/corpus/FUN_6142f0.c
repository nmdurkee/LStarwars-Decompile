/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6142f0; label: FUN_006142f0
 */

void FUN_006142f0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  short local_8 [2];
  short local_4 [2];
  
  piVar3 = param_1;
  if (param_1[1] != 0) {
    FUN_004ef660(&param_1,param_1[2] + param_1[1],1);
    piVar3[2] = piVar3[2] + 1;
  }
  if ('\0' < (char)param_1) {
    cVar4 = (char)param_1 + -1;
    param_1 = (int *)CONCAT31(param_1._1_3_,cVar4);
    if (*(int *)(in_ECX + 0xd6b4 + cVar4 * 0xc) == 1) {
      if (piVar3[1] != 0) {
        FUN_004ef660(local_8,piVar3[2] + piVar3[1],2);
        if (*piVar3 != 0) {
          FUN_00621180(local_8);
        }
        piVar3[2] = piVar3[2] + 2;
      }
      if (piVar3[1] != 0) {
        FUN_004ef660(local_4,piVar3[2] + piVar3[1],2);
        if (*piVar3 != 0) {
          FUN_00621180(local_4);
        }
        piVar3[2] = piVar3[2] + 2;
      }
      puVar5 = (undefined4 *)FUN_006be7f0((int)local_4[0]);
      iVar2 = local_8[0] * 3 + 6;
      iVar1 = in_ECX + iVar2 * 8;
      if (*(int *)(in_ECX + 0xc + iVar2 * 8) == 0) {
        if ((*(byte *)(in_ECX + 0xd6b8 + (char)param_1 * 0xc) & 1) != 0) {
          uVar9 = 0;
          puVar7 = puVar5;
          uVar8 = param_2;
          uVar6 = FUN_006c6330(puVar5[5],0,0,(int)local_8[0],1);
          FUN_00611e00((int)local_8[0],uVar6,puVar7,uVar8,uVar9);
        }
        if (*(int *)(iVar1 + 0xc) == 0) {
          return;
        }
      }
      if (*(undefined4 **)(iVar1 + 0x10) != puVar5) {
        FUN_00611890(**(undefined4 **)(iVar1 + 0x10),*puVar5,(int)local_8[0]);
      }
      (**(code **)(in_ECX + ((char)param_1 + 0x11e5) * 0xc))(*(undefined4 *)(iVar1 + 0xc),piVar3);
    }
  }
  return;
}

