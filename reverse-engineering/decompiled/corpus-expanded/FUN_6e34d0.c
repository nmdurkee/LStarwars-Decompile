/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e34d0; label: FUN_006e34d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e34d0(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (*(int *)(in_ECX + 0x638) != 0) {
    FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
    (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
              (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
    (**(code **)(**(int **)(in_ECX + 4) + 0xac))(*(int **)(in_ECX + 4),0,0,7,0,0x3f800000,0);
    FUN_006e33a0();
    return;
  }
  FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
  (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
  if (*(int *)(in_ECX + 0x6ec) == 0) {
    uVar5 = 0;
    uVar4 = 1;
  }
  else {
    uVar5 = 0xc0;
    uVar4 = 7;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0xac))(*(int **)(in_ECX + 4),0,0,uVar4,0,0x3f800000,uVar5);
  iVar3 = 0;
  do {
    if (iVar3 == 0) {
      iVar1 = *(int *)(in_ECX + 0x6c4);
      if (iVar1 == 0) {
        iVar1 = *(int *)(in_ECX + 0x6b0);
      }
      FUN_006e2880(0,iVar1);
      (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
                (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
LAB_006e361c:
      piVar2 = *(int **)(in_ECX + 4);
      iVar1 = *piVar2;
      uVar4 = 0;
LAB_006e362b:
      (**(code **)(iVar1 + 0xac))(piVar2,0,0,1,uVar4,0x3f800000,0);
    }
    else if (iVar3 == 1) {
      if (*(int *)(in_ECX + 0x6c8) != 0) {
        FUN_006e2880(1,0);
        FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6c8));
        piVar2 = *(int **)(in_ECX + 4);
        iVar1 = *piVar2;
        uVar4 = 0xff000000;
        goto LAB_006e362b;
      }
    }
    else if ((iVar3 == 2) && (*(int *)(in_ECX + 0x6cc) != 0)) {
      FUN_006e2880(2,0);
      FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6cc));
      goto LAB_006e361c;
    }
    iVar3 = iVar3 + 1;
    if (iVar3 == 4) {
      FUN_006e33a0();
      return;
    }
  } while( true );
}

