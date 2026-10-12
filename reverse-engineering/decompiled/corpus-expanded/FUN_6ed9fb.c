/* Ghidra pseudocode, not original source.
 * ev_a061266dd45b392e87f7d3689b136f273b070abf9372dc393200501f91b0ff88
 * Entry: 0x6ed9fb; label: _raise
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2005 Release */

int __cdecl _raise(int _SigNum)

{
  bool bVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_34;
  undefined4 local_30;
  int local_28;
  
  iVar6 = 0;
  bVar1 = false;
  if (_SigNum < 0xc) {
    if (_SigNum != 0xb) {
      if (_SigNum == 2) {
        puVar5 = &DAT_0297c1f8;
        uVar4 = DAT_0297c1f8;
        goto LAB_006edab0;
      }
      if (_SigNum != 4) {
        if (_SigNum == 6) goto LAB_006eda8e;
        if (_SigNum != 8) goto LAB_006eda72;
      }
    }
    iVar6 = FUN_006f0395();
    if (iVar6 == 0) {
      return -1;
    }
    iVar2 = siglookup(*(undefined4 *)(iVar6 + 0x5c));
    puVar5 = (undefined4 *)(iVar2 + 8);
    pcVar3 = (code *)*puVar5;
  }
  else {
    if (_SigNum == 0xf) {
      puVar5 = &DAT_0297c204;
      uVar4 = DAT_0297c204;
    }
    else if (_SigNum == 0x15) {
      puVar5 = &DAT_0297c1fc;
      uVar4 = DAT_0297c1fc;
    }
    else {
      if (_SigNum != 0x16) {
LAB_006eda72:
        puVar5 = (undefined4 *)FUN_006ead5f();
        *puVar5 = 0x16;
        FUN_006e9fc2(0,0,0,0,0);
        return -1;
      }
LAB_006eda8e:
      puVar5 = &DAT_0297c200;
      uVar4 = DAT_0297c200;
    }
LAB_006edab0:
    bVar1 = true;
    pcVar3 = (code *)FUN_006f01bc(uVar4);
  }
  if (pcVar3 == (code *)0x1) {
    return 0;
  }
  if (pcVar3 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (bVar1) {
    __lock(0);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = *(undefined4 *)(iVar6 + 0x60);
    *(undefined4 *)(iVar6 + 0x60) = 0;
    if (_SigNum == 8) {
      local_34 = *(undefined4 *)(iVar6 + 100);
      *(undefined4 *)(iVar6 + 100) = 0x8c;
      goto LAB_006edb14;
    }
  }
  else {
LAB_006edb14:
    if (_SigNum == 8) {
      for (local_28 = DAT_00829bf0; local_28 < DAT_00829bf4 + DAT_00829bf0; local_28 = local_28 + 1)
      {
        *(undefined4 *)(local_28 * 0xc + 8 + *(int *)(iVar6 + 0x5c)) = 0;
      }
      goto LAB_006edb4e;
    }
  }
  uVar4 = __encoded_null();
  *puVar5 = uVar4;
LAB_006edb4e:
  FUN_006edb6f();
  if (_SigNum == 8) {
    (*pcVar3)(8,*(undefined4 *)(iVar6 + 100));
  }
  else {
    (*pcVar3)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  *(undefined4 *)(iVar6 + 0x60) = local_30;
  if (_SigNum == 8) {
    *(undefined4 *)(iVar6 + 100) = local_34;
  }
  return 0;
}

