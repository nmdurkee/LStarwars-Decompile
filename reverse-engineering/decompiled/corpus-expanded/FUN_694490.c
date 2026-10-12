/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694490; label: FUN_00694490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00694490(uint param_1,undefined4 *param_2)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_4;
  
  if ((in_ECX == 0) || (DAT_02962b8c == 0)) {
    return 0;
  }
  uVar4 = 0;
  local_4 = 0;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
  }
  iVar5 = in_ECX + 0x130;
  iVar3 = 2;
  do {
    if ((*(int *)(iVar5 + 4 + *(int *)(iVar5 + 0x14) * 4) != 0) &&
       (uVar1 = *(uint *)(*(int *)(iVar5 + 4 + *(int *)(iVar5 + 0x14) * 4) + 0x14),
       (param_1 & uVar1) != 0)) {
      switch(*(undefined4 *)(iVar5 + 0x18)) {
      case 0:
      case 2:
      case 4:
      case 5:
      case 6:
        uVar4 = 1;
        break;
      case 1:
        uVar4 = 0;
        break;
      case 3:
        uVar4 = 2;
        break;
      case 7:
        uVar4 = 4;
      }
      local_4 = local_4 | uVar4;
      iVar2 = 0;
      do {
        if (uVar1 == 1 << ((byte)iVar2 & 0x1f)) goto LAB_0069452d;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 6);
      iVar2 = -1;
LAB_0069452d:
      if ((param_2 != (undefined4 *)0x0) && (iVar2 != -1)) {
        param_2[iVar2] = param_2[iVar2] | uVar4;
      }
    }
    iVar5 = iVar5 + 0x34;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return local_4;
    }
  } while( true );
}

