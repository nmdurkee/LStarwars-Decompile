/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694e70; label: FUN_00694e70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694e70(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int local_30;
  undefined1 local_2c [16];
  char *local_1c [7];
  
  local_1c[0] = "INVALID";
  local_1c[1] = "QUIET";
  local_1c[2] = "ACTION";
  local_1c[3] = "SIGNATURE";
  local_1c[4] = "OVERLAY";
  local_1c[5] = "CUTSCENE";
  local_1c[6] = "NOMUSIC";
  FUN_005d0880();
  FUN_005d0a40(1);
  FUN_005d0fb0();
  FUN_005eaad0();
  uVar6 = 0x3f4ccccd3f4ccccd;
  uVar5 = DAT_009738b8;
  FUN_005d0fe0();
  FUN_005d1060(DAT_009738b8,DAT_00810c14,uVar5,uVar6);
  iVar3 = 0;
  local_30 = 0;
  piVar4 = (int *)(in_ECX + 0x144);
  do {
    FUN_00698a40(piVar4[-5] * 2,local_2c);
    FUN_005f35e0(DAT_009738b8,0x12c0,param_2,0x10,"VOICE:%d",local_30);
    FUN_005d0e80(DAT_009738b8);
    iVar1 = FUN_006e6b90();
    param_2 = param_2 + iVar1;
    if (*(int *)(in_ECX + 0x134 + (*piVar4 + iVar3) * 4) == 0) {
      FUN_005f35e0(DAT_009738b8,0x12c0,param_2,0x10,"TRACK:NONE");
      FUN_005d0e80(DAT_009738b8);
      iVar1 = FUN_006e6b90();
      param_2 = param_2 + iVar1;
      FUN_005f35e0(DAT_009738b8,0x12c0,param_2,0x10,"CLASS:NONE");
    }
    else {
      FUN_005f35e0(DAT_009738b8,0x12c0,param_2,0x10,"TRACK:%s",
                   *(undefined4 *)
                    (*(int *)(in_ECX + 0x134 + (*piVar4 + iVar3) * 4) +
                    *(int *)(in_ECX + 0x13c + (*piVar4 + iVar3) * 4) * 4));
      FUN_005d0e80(DAT_009738b8);
      iVar1 = FUN_006e6b90();
      param_2 = param_2 + iVar1;
      iVar1 = 0;
      do {
        if (*(int *)(*(int *)(in_ECX + 0x134 + (*piVar4 + iVar3) * 4) + 0x14) ==
            1 << ((byte)iVar1 & 0x1f)) goto LAB_00694fe6;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
      iVar1 = -1;
LAB_00694fe6:
      FUN_005f35e0(DAT_009738b8,0x12c0,param_2,0x10,"CLASS:%s",local_1c[iVar1 + 1]);
    }
    FUN_005d0e80();
    iVar1 = FUN_006e6b90();
    FUN_005f35e0(DAT_009738b8,0x12c0,param_2 + iVar1,0x10,"STATUS:%s",
                 (&PTR_s_IDLE_PENDING_00810bf4)[piVar4[1]]);
    FUN_005d0e80(DAT_009738b8);
    iVar2 = FUN_006e6b90();
    iVar2 = param_2 + iVar1 + iVar2;
    FUN_005f35e0(DAT_009738b8,0x12c0,iVar2,0x10,"VOLUME:%f (%f)",(double)(float)piVar4[2],
                 (double)(float)piVar4[4]);
    FUN_005d0e80(DAT_009738b8);
    iVar1 = FUN_006e6b90();
    iVar2 = iVar2 + iVar1;
    FUN_005f35e0(DAT_009738b8,0x12c0,iVar2,0x10,"FADE:%f",(double)(float)piVar4[5]);
    FUN_005d0e80(DAT_009738b8);
    iVar1 = FUN_006e6b90();
    iVar2 = iVar2 + iVar1;
    FUN_005f35e0(DAT_009738b8,0x12c0,iVar2);
    FUN_005d0e80(DAT_009738b8);
    param_2 = FUN_006e6b90();
    local_30 = local_30 + 1;
    iVar3 = iVar3 + 0xd;
    param_2 = iVar2 + param_2;
    piVar4 = piVar4 + 0xd;
    if (0x19 < iVar3) {
      FUN_005d08c0();
      return;
    }
  } while( true );
}

