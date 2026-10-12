/* Ghidra pseudocode, not original source.
 * ev_c8c236b59c094db138f75ad711126508fb50275f6e5d8f12ab0ad6308e4435ce
 * Entry: 0x495900; label: FUN_00495900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00495900(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar1 = DAT_00826494;
  if (DAT_00826494 == 3) {
    iVar1 = DAT_02976bf4;
  }
  DAT_008668d7 = iVar1 != 0;
  if (*(int *)(param_1 + 100) != 0) {
    iVar1 = FUN_0055f1a0();
    if (DAT_0087b718 != 0) {
      iVar1 = 0;
    }
    DAT_00800940 = FUN_00547990(0x30);
    iVar4 = *(int *)(param_1 + 0x34);
    if (iVar4 == 0) {
      FUN_0055c560();
      return;
    }
    if (iVar4 == 1) {
      FUN_00509830(4,0xffffffff,0xffffffff);
      return;
    }
    if (iVar4 == 2) {
      FUN_00509830(0x15,0,0xffffffff);
      return;
    }
    if (iVar4 == 3) {
      FUN_00509830(0x401,0,0xffffffff);
      return;
    }
    iVar2 = 5;
    if (iVar4 == 4) {
      FUN_00509830(0x402,0,0xffffffff);
      return;
    }
    if ((DAT_0093b338 == 0) && (iVar2 = 6, iVar4 == 5)) {
      if ((DAT_0093b2a8 == 0) && ((DAT_00856c08 == 0 && (iVar1 = FUN_0058a900(0), iVar1 == 0)))) {
        FUN_00509830(5,0xffffffff,0xffffffff);
        return;
      }
      FUN_00547930(0x32,0,0,0);
      return;
    }
    iVar3 = iVar2;
    if ((iVar1 == 0) || (iVar3 = iVar2 + 1, iVar4 != iVar2)) {
      if (iVar4 == iVar3) {
        iVar1 = FUN_0055c780(PTR_DAT_00802c54,0xffffffff);
        FUN_00509830(6,(iVar1 != 0) + '\x01');
      }
    }
    else {
      iVar1 = -1;
      piVar5 = &DAT_0093d7f4;
      iVar4 = DAT_00802af8;
      iVar2 = 2;
      do {
        iVar3 = piVar5[-1];
        if (iVar3 != 0) {
          if (*(undefined4 **)(iVar3 + 0xca4) == &DAT_009253b0 + iVar4 * 0x18) {
            iVar1 = iVar2 + -2;
          }
          if (iVar3 != 0) {
            *(uint *)(iVar3 + 0xef0) = *(uint *)(iVar3 + 0xef0) & 0xffdfffff;
            iVar4 = DAT_00802af8;
          }
        }
        iVar3 = *piVar5;
        if (iVar3 != 0) {
          if (*(undefined4 **)(iVar3 + 0xca4) == &DAT_009253b0 + iVar4 * 0x18) {
            iVar1 = iVar2 + -1;
          }
          *(uint *)(iVar3 + 0xef0) = *(uint *)(iVar3 + 0xef0) & 0xffdfffff;
          iVar4 = DAT_00802af8;
        }
        iVar3 = piVar5[1];
        if (iVar3 != 0) {
          if (*(undefined4 **)(iVar3 + 0xca4) == &DAT_009253b0 + iVar4 * 0x18) {
            iVar1 = iVar2;
          }
          if (iVar3 != 0) {
            *(uint *)(iVar3 + 0xef0) = *(uint *)(iVar3 + 0xef0) & 0xffdfffff;
            iVar4 = DAT_00802af8;
          }
        }
        iVar3 = piVar5[2];
        if (iVar3 != 0) {
          if (*(undefined4 **)(iVar3 + 0xca4) == &DAT_009253b0 + iVar4 * 0x18) {
            iVar1 = iVar2 + 1;
          }
          if (iVar3 != 0) {
            *(uint *)(iVar3 + 0xef0) = *(uint *)(iVar3 + 0xef0) & 0xffdfffff;
            iVar4 = DAT_00802af8;
          }
        }
        iVar3 = iVar2 + 2;
        piVar5 = piVar5 + 4;
        iVar2 = iVar2 + 4;
      } while (iVar3 < 8);
      if (iVar1 != -1) {
        FUN_00427cd0(iVar1,1,0,0);
        return;
      }
    }
  }
  return;
}

