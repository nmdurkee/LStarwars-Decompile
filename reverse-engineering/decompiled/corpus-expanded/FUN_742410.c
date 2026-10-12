/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742410; label: FUN_00742410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00742410(int param_1,int *param_2,int *param_3)

{
  short *psVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint *local_3c;
  int local_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [8];
  short sStack_28;
  undefined1 uStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 uStack_10;
  
  *(undefined4 *)(param_1 + 0x10) = 0;
  local_38 = 0;
  local_3c = &DAT_0082b1e0;
  do {
    iVar7 = 1;
    if ((local_3c[-4] == 0) || (param_2 == (int *)0x0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = (**(code **)(*param_2 + 0x24))(param_2,0,local_3c[-4]);
      if ((iVar3 != 0) && (-1 < (int)local_3c[1])) {
        *local_3c = *local_3c | 1;
      }
    }
    piVar6 = param_2;
    if (iVar3 == 0) {
      iVar7 = 2;
      if ((local_3c[-3] == 0) || (param_3 == (int *)0x0)) {
        iVar3 = 0;
      }
      else {
        iVar3 = (**(code **)(*param_3 + 0x24))(param_3,0,local_3c[-3]);
        if ((iVar3 != 0) && (-1 < (int)local_3c[1])) {
          *local_3c = *local_3c | 2;
        }
      }
      piVar6 = param_3;
      if (iVar3 != 0) goto LAB_007424a2;
    }
    else {
LAB_007424a2:
      if ((DAT_02974d1c != 4) || ((int)local_3c[1] < 0)) {
        psVar4 = (short *)FUN_00743c90(param_1,local_38);
        *(uint *)(psVar4 + 2) = *(uint *)(psVar4 + 2) & 0xfffffff | iVar7 << 0x1c;
        uStack_34 = 1;
        (**(code **)(*piVar6 + 0x18))(piVar6,iVar3,auStack_30,&uStack_34);
        if (iStack_1c == 3) {
          if (iStack_20 == 0) {
            uVar5 = *(uint *)(psVar4 + 2) & 0xf1ffffff | 0x1000000;
LAB_00742582:
            *(uint *)(psVar4 + 2) = uVar5;
          }
          else if (iStack_20 == 1) {
            *(uint *)(psVar4 + 2) = *(uint *)(psVar4 + 2) & 0xf2ffffff | 0x2000000;
          }
          else if ((iStack_20 == 3) || (iStack_20 == 2)) {
            *(uint *)(psVar4 + 2) = *(uint *)(psVar4 + 2) & 0xf3ffffff | 0x3000000;
          }
        }
        else if ((((iStack_1c == 10) || (iStack_1c == 0xb)) || (iStack_1c == 0xc)) ||
                ((iStack_1c == 0xd || (iStack_1c == 0xe)))) {
          uVar5 = *(uint *)(psVar4 + 2) & 0xf4ffffff | 0x4000000;
          goto LAB_00742582;
        }
        *psVar4 = sStack_28;
        *(undefined1 *)(psVar4 + 2) = uStack_24;
        *(undefined1 *)((int)psVar4 + 5) = uStack_10;
        if (((*local_3c & 1) != 0) &&
           ((((iStack_1c == 10 || (iStack_1c == 0xb)) || (iStack_1c == 0xc)) ||
            ((iStack_1c == 0xd || (iStack_1c == 0xe)))))) {
          *psVar4 = sStack_28 + 0x101;
        }
        if (((DAT_02974d1c != 4) && (local_3c[2] != 0)) || ((int)local_3c[1] < 0)) {
          psVar1 = *(short **)(param_1 + 0x10);
          if ((psVar1 == (short *)0x0) || (*psVar4 <= *psVar1)) {
            *(short **)(psVar4 + 4) = psVar1;
            *(short **)(param_1 + 0x10) = psVar4;
          }
          else {
            iVar7 = *(int *)(psVar1 + 4);
            while ((iVar7 != 0 && (psVar2 = *(short **)(psVar1 + 4), *psVar2 <= *psVar4))) {
              iVar7 = *(int *)(psVar2 + 4);
              psVar1 = psVar2;
            }
            *(undefined4 *)(psVar4 + 4) = *(undefined4 *)(psVar1 + 4);
            *(short **)(psVar1 + 4) = psVar4;
          }
        }
      }
    }
    local_38 = local_38 + 1;
    local_3c = local_3c + 0x17;
    if (0x82d5cf < (int)local_3c) {
      return;
    }
  } while( true );
}

