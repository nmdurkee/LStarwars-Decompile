/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b15c0; label: FUN_004b15c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b15c0(int param_1,int param_2)

{
  uint *puVar1;
  float fVar2;
  char cVar3;
  byte bVar4;
  int in_EAX;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar8 = 0;
  iVar5 = FUN_00578790();
  cVar3 = *(char *)(in_EAX + 0x7b5);
  if (cVar3 == '\x1d') {
    *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x20000;
    *(float *)(in_EAX + 0x77c) = _DAT_00925018 + *(float *)(in_EAX + 0x77c);
    if ((*(byte *)(in_EAX + 0x1fc) & 0x80) != 0) {
      iVar8 = FUN_0054fa60(0);
      FUN_0054a850(**(undefined4 **)(in_EAX + 0xca4),(float)iVar8 * 1.5259022e-05 * 0.6);
    }
    if (*(int *)(in_EAX + 0xcb8) != 0) {
      puVar1 = (uint *)(*(int *)(in_EAX + 0xcb8) + 0x218);
      *puVar1 = *puVar1 | 1;
      puVar1 = (uint *)(*(int *)(in_EAX + 0xcb8) + 0x108);
      *puVar1 = *puVar1 & 0xffffbfff;
      if (*(float *)(in_EAX + 0x77c) < 0.2) {
        fVar9 = (float10)FUN_0054fb40(*(undefined4 *)(*(int *)(in_EAX + 0xcb8) + 0x84),
                                      _DAT_007fc058 * 0.5,_DAT_007fc05c + _DAT_007fc05c);
        *(float *)(*(int *)(in_EAX + 0xcb8) + 0x84) = (float)fVar9;
      }
      iVar8 = *(int *)(*(int *)(in_EAX + 0xcb8) + 0xd4);
      if ((iVar8 == 0) || (*(char *)(iVar8 + 0x280) != -1)) {
        FUN_005b3620(local_18,&DAT_0080250c,*(undefined2 *)(in_EAX + 0x58));
      }
      else {
        FUN_005b3800(local_18,iVar8 + 0x80,*(int *)(in_EAX + 0xcb8) + 0x30);
        FUN_005b3b30(local_18,local_18);
      }
      FUN_005b3830(local_c,local_18,_DAT_007fc058);
      iVar8 = *(int *)(in_EAX + 0xcb8) + 0x80;
      FUN_0054fb80(iVar8,iVar8,local_c,_DAT_007fc05c);
      *(undefined4 *)(in_EAX + 0xd18) = *(undefined4 *)(in_EAX + 0xcb8);
      *(undefined1 *)(in_EAX + 0xe2d) = 3;
      FUN_0058bee0();
      iVar8 = *(int *)(in_EAX + 0xcb8);
      if (*(code **)(iVar8 + 0x1b0) == FUN_004a56a0) {
        *(undefined4 *)(iVar8 + 0x1b0) = 0;
        *(undefined4 *)(*(int *)(in_EAX + 0xcb8) + 0x1b4) = 0;
        puVar1 = (uint *)(*(int *)(in_EAX + 0xcb8) + 0x108);
        *puVar1 = *puVar1 & 0xffffbfff;
        puVar1 = (uint *)(*(int *)(in_EAX + 0xcb8) + 0x108);
        *puVar1 = *puVar1 | 0x80;
        FUN_0064a740(*(undefined4 *)(in_EAX + 0xcb8));
      }
      else if ((*(code **)(iVar8 + 0x1b0) == FUN_004e36d0) &&
              (fVar2 = *(float *)(in_EAX + 0x77c), !NAN(fVar2) && 0.5 < fVar2 != (fVar2 == 0.5))) {
        FUN_004e3810(iVar8,0);
      }
    }
    if ((((param_2 == 0) && ((*(uint *)(in_EAX + 0xef0) & 0x100) == 0)) ||
        (*(int *)(in_EAX + 0xcb8) == 0)) ||
       ((fVar2 = *(float *)(in_EAX + 0x784), NAN(fVar2) || 0.2 < fVar2 == (fVar2 == 0.2) ||
        (1.5 <= *(float *)(in_EAX + 0x77c))))) {
      fVar2 = *(float *)(in_EAX + 0x784) - _DAT_00925018;
      *(float *)(in_EAX + 0x784) = fVar2;
      if (fVar2 <= 0.0) {
        FUN_004a25b0();
        return;
      }
    }
    else {
      fVar2 = *(float *)(in_EAX + 0x784) - _DAT_00925018;
      *(float *)(in_EAX + 0x784) = fVar2;
      if (fVar2 < 0.2 != (fVar2 == 0.2)) {
        *(undefined4 *)(in_EAX + 0x784) = 0x3e4ccccd;
        return;
      }
    }
  }
  else {
    uVar6 = *(uint *)(in_EAX + 0x1fc) >> 7 & 1;
    if (((uVar6 == 0) && ((*(uint *)(in_EAX + 0xef0) & 0x100) != 0)) && (DAT_0093d810 != 0)) {
      iVar8 = *(int *)(DAT_0093d810 + 0xcb8);
    }
    if ((((uVar6 != 0) || (iVar8 != 0)) && (*(char *)(in_EAX + 0x281) != '\0')) &&
       (((cVar3 == -1 || ((*(uint *)(PTR_PTR_007fb0e4 + cVar3 * 0x10 + 8) & 4) != 0)) ||
        ((cVar3 == '\x06' || ((cVar3 == '\a' || (iVar7 = FUN_00578790(), iVar7 != 0)))))))) {
      if (iVar5 == 0) {
        iVar7 = iVar8;
        if (iVar8 == 0) {
          iVar7 = FUN_00571cf0();
        }
      }
      else {
        iVar7 = *(int *)(in_EAX + 0xcb8);
      }
      if (iVar7 != 0) {
        *(uint *)(in_EAX + 0xe20) = *(uint *)(in_EAX + 0xe20) | 0x20000;
        *(int *)(in_EAX + 0xd18) = iVar7;
        *(undefined1 *)(in_EAX + 0xe2d) = 3;
        FUN_0058bee0();
        if (((param_1 != 0) || (iVar8 != 0)) || (iVar5 != 0)) {
          *(int *)(in_EAX + 0xcb8) = iVar7;
          *(undefined4 *)(iVar7 + 0xe8) = 0;
          puVar1 = (uint *)(*(int *)(in_EAX + 0xcb8) + 0x108);
          *puVar1 = *puVar1 | 0x10000;
          *(undefined4 *)(in_EAX + 0x77c) = 0;
          *(undefined4 *)(in_EAX + 0x784) = 0x3e99999a;
          iVar8 = *(int *)(in_EAX + 0xcb8);
          *(undefined4 *)(in_EAX + 0x790) = 0;
          *(undefined4 *)(in_EAX + 0x794) = 0;
          *(undefined1 *)(in_EAX + 0x7b5) = 0x1d;
          bVar4 = (byte)(1 << (*(byte *)(in_EAX + 0x280) & 0x1f));
          if (*(char *)(iVar8 + 0x206) == -1) {
            *(byte *)(iVar8 + 0x206) = bVar4;
          }
          else {
            *(byte *)(iVar8 + 0x206) = *(byte *)(iVar8 + 0x206) | bVar4;
          }
          FUN_0054a3e0(PTR_DAT_008021b4,0x3f000000,0,1);
          FUN_00681f40("JForcePush",in_EAX + 0x80);
        }
      }
    }
  }
  return;
}

