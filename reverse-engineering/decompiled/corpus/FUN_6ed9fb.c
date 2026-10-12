/* Ghidra analysis pseudocode, not original source.
 * ev_5fe54c2a55e5805f81bff5ddaf4fd9cf0184cfdba0adc5a7ca08f803c24de38d
 * Entry: 0x6ed9fb; label: _raise
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _raise
   
   Library: Visual Studio 2005 Release */

int __cdecl _raise(int _SigNum)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_34;
  undefined4 local_30;
  int local_28;
  int local_20;
  
  iVar5 = 0;
  local_20 = 0;
  if (_SigNum < 0xc) {
    if (_SigNum != 0xb) {
      if (_SigNum == 2) {
        puVar4 = &DAT_0297c1f8;
        uVar3 = DAT_0297c1f8;
        goto LAB_006edab0;
      }
      if (_SigNum != 4) {
        if (_SigNum == 6) goto LAB_006eda8e;
        if (_SigNum != 8) goto LAB_006eda72;
      }
    }
    iVar5 = FUN_006f0395();
    if (iVar5 == 0) {
      return -1;
    }
    iVar1 = siglookup(*(undefined4 *)(iVar5 + 0x5c));
    puVar4 = (undefined4 *)(iVar1 + 8);
    pcVar2 = (code *)*puVar4;
  }
  else {
    if (_SigNum == 0xf) {
      puVar4 = &DAT_0297c204;
      uVar3 = DAT_0297c204;
    }
    else if (_SigNum == 0x15) {
      puVar4 = &DAT_0297c1fc;
      uVar3 = DAT_0297c1fc;
    }
    else {
      if (_SigNum != 0x16) {
LAB_006eda72:
        puVar4 = (undefined4 *)FUN_006ead5f();
        *puVar4 = 0x16;
        FUN_006e9fc2(0,0,0,0,0);
        return -1;
      }
LAB_006eda8e:
      puVar4 = &DAT_0297c200;
      uVar3 = DAT_0297c200;
    }
LAB_006edab0:
    local_20 = 1;
    pcVar2 = (code *)FUN_006f01bc(uVar3);
  }
  iVar1 = 0;
  if (pcVar2 == (code *)0x1) {
    return 0;
  }
  if (pcVar2 == (code *)0x0) {
    iVar1 = __exit(3);
  }
  if (local_20 != iVar1) {
    __lock(iVar1);
  }
  if (((_SigNum == 8) || (_SigNum == 0xb)) || (_SigNum == 4)) {
    local_30 = *(undefined4 *)(iVar5 + 0x60);
    *(undefined4 *)(iVar5 + 0x60) = 0;
    if (_SigNum == 8) {
      local_34 = *(undefined4 *)(iVar5 + 100);
      *(undefined4 *)(iVar5 + 100) = 0x8c;
      goto LAB_006edb14;
    }
  }
  else {
LAB_006edb14:
    if (_SigNum == 8) {
      for (local_28 = DAT_00829bf0; local_28 < DAT_00829bf4 + DAT_00829bf0; local_28 = local_28 + 1)
      {
        *(undefined4 *)(local_28 * 0xc + 8 + *(int *)(iVar5 + 0x5c)) = 0;
      }
      goto LAB_006edb4e;
    }
  }
  uVar3 = __encoded_null();
  *puVar4 = uVar3;
LAB_006edb4e:
  FUN_006edb6f();
  if (_SigNum == 8) {
    (*pcVar2)(8,*(undefined4 *)(iVar5 + 100));
  }
  else {
    (*pcVar2)(_SigNum);
    if ((_SigNum != 0xb) && (_SigNum != 4)) {
      return 0;
    }
  }
  *(undefined4 *)(iVar5 + 0x60) = local_30;
  if (_SigNum == 8) {
    *(undefined4 *)(iVar5 + 100) = local_34;
  }
  return 0;
}

