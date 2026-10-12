/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46af20; label: FUN_0046af20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046af20(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = FUN_00570bb0();
  if (iVar4 == 0) {
    cVar1 = *(char *)(param_1 + 0xfd);
    if ((((cVar1 == '\0') || (cVar1 == '\x01')) && (iVar4 = (&DAT_0093d7f0)[cVar1], iVar4 != 0)) &&
       (puVar2 = *(undefined4 **)(iVar4 + 0x7fc), puVar2 != (undefined4 *)0x0)) {
      uVar3 = *puVar2;
      if (*(short *)(param_1 + 0xe6) != -1) {
        *(short *)(puVar2 + 2) = *(short *)(param_1 + 0xe6);
      }
      if (DAT_007f3b14 == -1) {
        FUN_005533f0(*(undefined4 *)(iVar4 + 0x7fc),*(undefined4 *)(param_1 + 0xdc),0,1);
        *(undefined4 *)(*(int *)(iVar4 + 0x7fc) + 4) = 0x3fc00000;
      }
      if (DAT_0087b980 == 0) {
        _DAT_0087b92c = 0x3fc00000;
      }
      if (DAT_0093b324 == 0) {
        if (((DAT_00951154 != 0) && (DAT_007f3b14 == -1)) && (999999 < **(uint **)(iVar4 + 0x7fc)))
        {
          **(uint **)(iVar4 + 0x7fc) = 1000000;
          FUN_0042b6f0((int)*(char *)(param_1 + 0xfd));
          DAT_0086e71c = 0;
          FUN_00509830(0x13,0xffffffff,0xffffffff);
          FUN_00681f40("MK-Panel",0);
          FUN_00560b40();
        }
      }
      else {
        FUN_00476120((int)*(char *)(param_1 + 0xfd),*(undefined4 *)(iVar4 + 0x7fc),uVar3);
      }
    }
  }
  else {
    if (*(short *)(param_1 + 0xe6) != -1) {
      iVar4 = (int)*(short *)(param_1 + 0xe6);
      if (iVar4 - 0xb7U < 4) {
        iVar4 = iVar4 + -4;
      }
      else if (iVar4 - 0xbfU < 4) {
        iVar4 = iVar4 + -4;
      }
      else if (iVar4 - 199U < 4) {
        iVar4 = iVar4 + -4;
      }
      else if (iVar4 - 0xd5U < 4) {
        iVar4 = iVar4 + 4;
      }
      (&DAT_007fc374)[*(char *)(param_1 + 0xfd)] = iVar4;
    }
    _DAT_0087b93c = 0x3fc00000;
    if (DAT_0093b2a8 == 0) {
      iVar4 = FUN_0055f450();
      if ((*(int *)(iVar4 + 300) == 0) || ((*(ushort *)(*(int *)(iVar4 + 300) + 0x7a) & 0x100) == 0)
         ) {
        FUN_005533f0(&DAT_0086e4dc,*(undefined4 *)(param_1 + 0xdc),0,1);
      }
      else if ((DAT_0085ea74 < DAT_008668c4) &&
              (FUN_005533f0(&DAT_0085ea74,*(undefined4 *)(param_1 + 0xdc),0,0),
              DAT_008668c4 <= DAT_0085ea74)) {
        DAT_0085ea74 = DAT_008668c4;
        FUN_0042b6f0((int)*(char *)(param_1 + 0xfd));
        DAT_0086e71c = 0;
        FUN_00509830(0x14,0xffffffff,0xffffffff);
        FUN_00681f40("MK-Panel",0);
        FUN_00560b40();
      }
    }
    else {
      FUN_005533f0(&DAT_0093b298,*(undefined4 *)(param_1 + 0xdc),0,0);
    }
  }
  if (_DAT_00925040 <= 0.0) {
    FUN_00681f40("Counter",0);
    return;
  }
  FUN_005487c0("Counter",0xffffffff,0,2,0x3dcccccd);
  return;
}

