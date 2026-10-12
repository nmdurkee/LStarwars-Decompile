/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6b0350; label: FUN_006b0350
 */

void FUN_006b0350(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  undefined4 uVar6;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  _memset(param_2,0,0x30);
  if ((piVar1 + 0x348 != (int *)0x0) && (0 < piVar1[0x34b])) {
    iVar2 = *piVar1;
    iVar3 = piVar1[1];
    dVar4 = (double)(iVar2 >> 1);
    dVar5 = (double)*(int *)(param_1 + 8);
    *param_2 = 1;
    param_2[6] = iVar3 / iVar2;
    FUN_006eafc0(((double)piVar1[0x348] * dVar4) / dVar5 + 0.5);
    uVar6 = FUN_006e6b90();
    param_2[3] = uVar6;
    FUN_006eafc0(((double)piVar1[0x349] * dVar4) / dVar5 + 0.5);
    uVar6 = FUN_006e6b90();
    param_2[4] = uVar6;
    FUN_006eafc0(((double)piVar1[0x34a] * dVar4) / dVar5 + 0.5);
    uVar6 = FUN_006e6b90();
    *(undefined8 *)(param_2 + 8) = 0x401c000000000000;
    param_2[5] = uVar6;
    uVar6 = FUN_006e6b90();
    param_2[2] = uVar6;
    param_2[1] = uVar6;
  }
  return;
}

