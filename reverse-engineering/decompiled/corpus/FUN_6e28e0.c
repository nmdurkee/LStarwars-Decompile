/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e28e0; label: FUN_006e28e0
 */

undefined4 FUN_006e28e0(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  int *piVar6;
  int *piStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  int *piStack_1c;
  int *local_8;
  
  uVar5 = 0;
  piVar6 = param_1;
  if (param_1 == (int *)0x0) {
    piVar6 = *(int **)(in_ECX + 0x138);
  }
  local_8 = param_2;
  if (param_2 == (int *)0x0) {
    switch(DAT_00826494) {
    default:
      fVar1 = 1.3333334;
      break;
    case 1:
      fVar1 = 1.7777778;
      break;
    case 2:
      fVar1 = 1.6;
      break;
    case 3:
      fVar1 = *(float *)(in_ECX + 0x630);
    }
    fVar2 = (float)(int)piVar6;
    if ((int)piVar6 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_8 = (int *)(longlong)ROUND(fVar2 / fVar1);
  }
  piStack_1c = (int *)0x0;
  piStack_20 = (int *)&param_1;
  uStack_24 = 0;
  uStack_28 = 0;
  piStack_2c = (int *)0x0;
  param_1 = (int *)0x0;
  param_2 = (int *)0x0;
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x70))(*(int **)(in_ECX + 4));
  if (-1 < iVar4) {
    if (piStack_20 == (int *)0x0) goto LAB_006e2aa1;
    iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x90))
                      (*(int **)(in_ECX + 4),piVar6,local_8,0x15,2,&piStack_1c,0);
    if ((((-1 < iVar4) && (piStack_1c != (int *)0x0)) &&
        (iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x88))
                           (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6e8),0,piStack_20,0,2),
        -1 < iVar4)) &&
       (iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x80))
                          (*(int **)(in_ECX + 4),piStack_20,piStack_1c), -1 < iVar4)) {
      piStack_2c = (int *)0x0;
      iVar4 = D3DXSaveSurfaceToFileInMemory(&piStack_2c,0,piStack_1c,0,0);
      if (-1 < iVar4) {
        uVar5 = (**(code **)(*piStack_2c + 0x10))(piStack_2c,".\\d3dCore.cpp",0x989);
        iVar4 = FUN_004eef40(uVar5);
        piVar3 = piStack_1c;
        *piStack_1c = iVar4;
        uVar5 = (**(code **)(iRam00000015 + 0x10))(0x15);
        uVar5 = (**(code **)(*local_8 + 0xc))(local_8,uVar5);
        FUN_004ef660(*piVar3,uVar5);
        uVar5 = (**(code **)(*piVar6 + 0x10))(piVar6);
      }
    }
  }
  if (piStack_20 != (int *)0x0) {
    (**(code **)(*piStack_20 + 8))(piStack_20);
    piStack_20 = (int *)0x0;
  }
LAB_006e2aa1:
  if (piStack_1c != (int *)0x0) {
    (**(code **)(*piStack_1c + 8))(piStack_1c);
    piStack_1c = (int *)0x0;
  }
  if (piStack_2c != (int *)0x0) {
    (**(code **)(*piStack_2c + 8))(piStack_2c);
  }
  return uVar5;
}

