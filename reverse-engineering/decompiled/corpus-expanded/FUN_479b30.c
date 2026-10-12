/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x479b30; label: FUN_00479b30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00479b30(undefined4 param_1)

{
  uint *puVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  
  FUN_00424350(DAT_00856980);
  if (DAT_00879b4c != (code *)0x0) {
    (*DAT_00879b4c)(param_1);
  }
  puVar6 = &DAT_0087ad48;
  iVar4 = 0x20;
  do {
    uVar7 = __allshl();
    if (((uint)uVar7 & _DAT_0087a9a0) != 0 ||
        ((uint)((ulonglong)uVar7 >> 0x20) & _DAT_0087a9a4) != 0) {
      FUN_005cfc00(puVar6 + -0x180,1);
    }
    uVar7 = __allshl();
    if (((uint)uVar7 & _DAT_0087a9a0) != 0 ||
        ((uint)((ulonglong)uVar7 >> 0x20) & _DAT_0087a9a4) != 0) {
      FUN_005cfc00(puVar6,0);
    }
    puVar6 = puVar6 + 0xc;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar4 = FUN_005cfac0(&DAT_0087aec8);
  if (iVar4 != 0) {
    FUN_005cfc00(&DAT_0087aec8,0);
  }
  iVar4 = 0;
  if (PTR_s_negotiations_007f9368 != (undefined *)0x0) {
    iVar5 = 0;
    do {
      if (*(int *)((int)&DAT_007f938c + iVar5) != 0) {
        iVar2 = FUN_0059b840((int)*(char *)(*(int *)((int)&DAT_007f9388 + iVar5) + 0x86),
                             *(undefined1 *)(*(int *)((int)&DAT_007f9388 + iVar5) + 0x7c),
                             DAT_0095136c);
        if (iVar2 == 0) {
          puVar1 = (uint *)(**(int **)((int)&DAT_007f938c + iVar5) + 0x9c);
          *puVar1 = *puVar1 | 8;
        }
        else {
          puVar1 = (uint *)(**(int **)((int)&DAT_007f938c + iVar5) + 0x9c);
          *puVar1 = *puVar1 & 0xfffffff7;
        }
        FUN_005cfc00(&DAT_007f9390 + iVar5,iVar2 != 0);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar4 * 0x3c;
    } while ((&PTR_s_negotiations_007f9368)[iVar4 * 0xf] != (undefined *)0x0);
  }
  iVar4 = 0;
  if (-1 < DAT_007f9f70) {
    psVar3 = &DAT_007f9f70;
    iVar5 = 0;
    do {
      if (8 < *psVar3) {
        _DAT_00879550 = 0;
        _DAT_00879b24 = 0;
        _DAT_00879b28 = 0;
        _DAT_00879b30 = 0;
        DAT_00879b78 = 0;
        return;
      }
      if (*(int *)((int)&DAT_007f9f88 + iVar5) != 0) {
        iVar2 = FUN_0059b840((int)*psVar3,0xffffffff,DAT_0095136c);
        if ((iVar2 == 0) && ((&DAT_007f9f7c)[iVar5] == '\0')) {
          puVar1 = (uint *)(**(int **)((int)&DAT_007f9f88 + iVar5) + 0x9c);
          *puVar1 = *puVar1 | 8;
          uVar8 = 0;
        }
        else {
          puVar1 = (uint *)(**(int **)((int)&DAT_007f9f88 + iVar5) + 0x9c);
          *puVar1 = *puVar1 & 0xfffffff7;
          uVar8 = 1;
        }
        FUN_005cfc00(&DAT_007f9f8c + iVar5,uVar8);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar4 * 0x28;
      psVar3 = &DAT_007f9f70 + iVar4 * 0x14;
    } while (-1 < (&DAT_007f9f70)[iVar4 * 0x14]);
  }
  _DAT_00879550 = 0;
  _DAT_00879b24 = 0;
  _DAT_00879b28 = 0;
  DAT_00879b78 = 0;
  _DAT_00879b30 = 0;
  return;
}

