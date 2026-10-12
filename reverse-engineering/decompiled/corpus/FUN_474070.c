/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x474070; label: FUN_00474070
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00474070(undefined4 param_1,float param_2,int param_3)

{
  char cVar1;
  undefined2 uVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  fVar4 = param_2;
  iVar6 = *(int *)((int)param_2 + 0x798);
  if (0.0 < *(float *)((int)param_2 + 0xdb0)) {
    *(float *)((int)param_2 + 0xdb0) = *(float *)((int)param_2 + 0xdb0) - _DAT_00925018;
  }
  if ((*(char *)((int)param_2 + 0x7b5) == 'a') && (iVar6 != 0)) {
    if ((*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) +
                 *(short *)((int)param_2 + 0x7aa) * 4) == 0) ||
       (iVar5 = FUN_0062f150((int)param_2 + 8,(int)*(short *)((int)param_2 + 0x7aa),1,0), iVar5 != 0
       )) {
      fVar3 = *(float *)((int)fVar4 + 0x778) + _DAT_00925018;
      *(float *)((int)fVar4 + 0x778) = fVar3;
      if (1.0 < fVar3) {
        *(undefined4 *)((int)fVar4 + 0x778) = 0x3f800000;
      }
      cVar1 = *(char *)((int)fVar4 + 0x7b3);
      param_2 = *(float *)((int)fVar4 + 0x77c) - _DAT_00925018;
      *(float *)((int)fVar4 + 0x77c) = param_2;
      if (cVar1 == '\0') {
        if (param_2 < 0.0 != (param_2 == 0.0)) {
          iVar5 = *(int *)(*(int *)((int)fVar4 + 0x50) + 0xc);
          if ((*(int *)(iVar5 + 0x1b4) != 0) &&
             (((*(byte *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x90) & 0x10) != 0 ||
              ((*(short *)((int)fVar4 + 0x1064) == DAT_007f186c && (DAT_0093b2a4 != 0)))))) {
            if (*(char *)(iVar6 + 0x60) == '\x02') {
              *(undefined2 *)((int)fVar4 + 0x7aa) = 0x6d;
              *(undefined1 *)((int)fVar4 + 0x7b3) = 1;
              fVar7 = (float10)FUN_0062e040((int)*(short *)((int)fVar4 + 0x1064),0x6d,0,0,1);
              *(float *)((int)fVar4 + 0x77c) = (float)fVar7;
              *(float *)(iVar6 + 0x88) = (float)fVar7 * 0.35;
              return;
            }
LAB_004743b2:
            *(undefined2 *)((int)fVar4 + 0x7aa) = 1;
            return;
          }
          if (*(int *)(iVar5 + 0x178) == 0) {
            if (*(char *)(iVar6 + 0x60) == '\x02') {
              *(undefined2 *)((int)fVar4 + 0x7aa) = 1;
              *(undefined1 *)((int)fVar4 + 0x7b3) = 1;
              *(undefined4 *)(iVar6 + 0x88) = 0x3e4ccccd;
              return;
            }
          }
          else {
            if (*(char *)(iVar6 + 0x60) != '\x02') goto LAB_004743b2;
            *(undefined2 *)((int)fVar4 + 0x7aa) = 0x5e;
            *(undefined1 *)((int)fVar4 + 0x7b3) = 1;
            fVar7 = (float10)FUN_0062e040((int)*(short *)((int)fVar4 + 0x1064),0x5e,0,0,1);
            *(float *)((int)fVar4 + 0x77c) = (float)fVar7;
            if (DAT_007f39e4 == 0) {
              *(float *)(iVar6 + 0x88) = (float)fVar7 * 0.35;
              return;
            }
          }
        }
      }
      else {
        if (cVar1 == '\x01') {
          if (*(char *)(iVar6 + 0x60) != '\x04') {
            return;
          }
          if (((*(byte *)(*(int *)(*(int *)((int)fVar4 + 0x54) + 0x24) + 0x90) & 0x10) == 0) &&
             ((*(short *)((int)fVar4 + 0x1064) != DAT_007f186c || (DAT_0093b2a4 == 0)))) {
            FUN_00681f40("HatOn",(int)fVar4 + 400);
            cVar1 = *(char *)(*(int *)((int)fVar4 + 0x798) + 0x5f);
            *(char *)((int)fVar4 + 0x1082) = cVar1;
            if (cVar1 == '\x05') {
              FUN_0043a910(1);
            }
          }
          *(undefined1 *)(iVar6 + 0x5f) = 0;
          *(undefined1 *)((int)fVar4 + 0x7b3) = 2;
          if (DAT_007f39e4 != 0) {
            *(undefined1 *)(iVar6 + 0x60) = 6;
          }
        }
        else if (cVar1 != '\x02') {
          return;
        }
        if (*(float *)((int)fVar4 + 0x77c) <= 0.0) {
          *(undefined4 *)((int)fVar4 + 0x77c) = 0;
          *(undefined1 *)((int)fVar4 + 0x7b5) = 0xff;
          if (*(int *)((int)fVar4 + 0x798) != 0) {
            if (*(char *)(*(int *)((int)fVar4 + 0x798) + 0x5e) == '\x06') {
              FUN_00681f40("Hunter_Granted",(int)fVar4 + 0x80);
            }
            if (*(char *)(*(int *)((int)fVar4 + 0x798) + 0x5e) == '\x05') {
              FUN_00681f40("Trooper_Granted",(int)fVar4 + 0x80);
            }
            *(undefined4 *)((int)fVar4 + 0x798) = 0;
            return;
          }
        }
      }
    }
    else {
      param_2 = *(float *)((int)fVar4 + 0x77c) - _DAT_00925018;
      *(float *)((int)fVar4 + 0x77c) = param_2;
      if (param_2 <= 0.0) {
        if (*(int *)((int)fVar4 + 0x798) == 0) {
          FUN_0054a850(**(undefined4 **)((int)fVar4 + 0xca4),0x3f000000,0);
        }
        else {
          FUN_0054a8a0(**(undefined4 **)((int)fVar4 + 0xca4),0x3dcccccd);
          *(undefined4 *)(*(int *)((int)fVar4 + 0x798) + 0x84) = 0x3f19999a;
          if (*(char *)(*(int *)((int)fVar4 + 0x798) + 0x5e) == '\x06') {
            FUN_00681f40("Hunter_Granted",(int)fVar4 + 0x80);
          }
          if (*(char *)(*(int *)((int)fVar4 + 0x798) + 0x5e) == '\x05') {
            FUN_00681f40("Trooper_Granted",(int)fVar4 + 0x80);
            *(undefined4 *)((int)fVar4 + 0x798) = 0;
            *(undefined1 *)((int)fVar4 + 0x7b5) = 0xff;
            return;
          }
        }
        *(undefined4 *)((int)fVar4 + 0x798) = 0;
        *(undefined1 *)((int)fVar4 + 0x7b5) = 0xff;
        return;
      }
    }
  }
  else if ((*(int *)(*(int *)(*(int *)((int)param_2 + 0x50) + 0xc) + 0x174) != 0) &&
          ((*(char *)((int)param_2 + 0x281) != '\0' && (iVar6 = FUN_005620f0(param_2), iVar6 != 0)))
          ) {
    iVar6 = (int)fVar4 + 0x80;
    iVar5 = FUN_00472d90(param_1,iVar6,fVar4,&param_2);
    if (iVar5 != 0) {
      fVar3 = (*(float *)((int)fVar4 + 0x1dc) + 0.25) * *(float *)(iVar5 + 0x90);
      if ((param_2 < fVar3) &&
         ((param_3 != 0 ||
          ((*(int *)((int)fVar4 + 0x79c) == 2 && (*(int *)((int)fVar4 + 0x7a0) != 0)))))) {
        *(int *)((int)fVar4 + 0x798) = iVar5;
        uVar2 = *(undefined2 *)(iVar5 + 0x5c);
        *(undefined4 *)((int)fVar4 + 0x778) = 0;
        *(uint *)((int)fVar4 + 0xe20) = *(uint *)((int)fVar4 + 0xe20) & 0xffffefff;
        *(undefined4 *)((int)fVar4 + 0xd48) = 0;
        *(undefined2 *)((int)fVar4 + 0x5a) = uVar2;
        *(undefined1 *)((int)fVar4 + 0x7b5) = 0x61;
        *(undefined1 *)((int)fVar4 + 0x7b3) = 0;
        param_2 = fVar3;
        FUN_0058d930(fVar4,0);
        *(uint *)((int)fVar4 + 0xe24) = *(uint *)((int)fVar4 + 0xe24) | 0x200;
        *(undefined2 *)((int)fVar4 + 0x7aa) = 0x5d;
        *(undefined1 *)(iVar5 + 0x60) = 1;
        if (DAT_007f39e4 == 0) {
          fVar7 = (float10)FUN_0062e040((int)*(short *)((int)fVar4 + 0x1064),
                                        (int)*(short *)((int)fVar4 + 0x7aa),0,0,1);
        }
        else {
          fVar7 = (float10)3.0;
        }
        *(float *)(iVar5 + 0x88) = (float)fVar7;
        fVar7 = (float10)FUN_0062f1f0(*(undefined4 *)((int)fVar4 + 0x50),
                                      (int)*(short *)((int)fVar4 + 0x7aa),0);
        *(byte *)(iVar5 + 99) = *(byte *)(iVar5 + 99) | 1;
        param_2 = (float)-fVar7;
        *(float *)(iVar5 + 0x8c) = param_2;
        *(float *)(iVar5 + 0x88) = *(float *)(iVar5 + 0x88) - param_2;
        *(undefined4 *)(iVar5 + 0x98) = 0;
        FUN_00433aa0(fVar4,0,0);
        FUN_0054a850(**(undefined4 **)((int)fVar4 + 0xca4),0x3f000000,0);
        if (*(char *)((int)fVar4 + 0x39) != '\0') {
          FUN_0062e650((int)fVar4 + 8,0xffffffff);
        }
        FUN_004399e0(fVar4,iVar6);
        fVar7 = (float10)FUN_0062e040((int)*(short *)((int)fVar4 + 0x1064),
                                      (int)*(short *)((int)fVar4 + 0x7aa),0,0,1);
        *(float *)((int)fVar4 + 0x77c) = (float)fVar7;
        *(float *)(*(int *)((int)fVar4 + 0x798) + 0x88) = (float)fVar7;
        if (*(float *)((int)fVar4 + 0x77c) <= 0.0) {
          *(undefined4 *)((int)fVar4 + 0x77c) = 0x40000000;
        }
        *(undefined4 *)((int)fVar4 + 0xdb0) = 0;
        return;
      }
      if ((((*(byte *)((int)fVar4 + 0x1fc) & 0x80) != 0) &&
          ((*(byte *)(*(int *)((int)fVar4 + 0x54) + 4) & 0x20) != 0)) &&
         (*(float *)((int)fVar4 + 0xdb0) <= 0.0)) {
        param_2 = fVar3;
        FUN_00681f40("TC14_VLN",iVar6);
        *(undefined4 *)((int)fVar4 + 0xdb0) = 0x3f000000;
        return;
      }
    }
  }
  return;
}

