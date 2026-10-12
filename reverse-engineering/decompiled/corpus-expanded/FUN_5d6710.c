/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d6710; label: FUN_005d6710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005d6710(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  if (param_3 == 0) {
    puVar3 = &DAT_0080b708;
    puVar4 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  else {
    FUN_005c1240(local_40,param_3,&DAT_0080b708);
  }
  uVar5 = 0xffffffff;
  if (0 < param_2) {
    do {
      FUN_005b30a0(&local_4c,param_1,local_40);
      uVar2 = 0;
      if (local_44 < DAT_00973730) {
        uVar2 = 0x20;
      }
      if (DAT_00973734 < local_44) {
        uVar2 = uVar2 | 0x10;
      }
      if (local_4c < DAT_00966378 * -local_44) {
        uVar2 = uVar2 | 1;
      }
      if (DAT_00966378 * local_44 < local_4c) {
        uVar2 = uVar2 | 2;
      }
      if (local_48 < DAT_0097313c * -local_44) {
        uVar2 = uVar2 | 8;
      }
      if (DAT_0097313c * local_44 < local_48) {
        uVar2 = uVar2 | 4;
      }
      uVar5 = uVar5 & uVar2;
      param_1 = param_1 + 0xc;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return uVar5;
}

