/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6992c0; label: FUN_006992c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006992c0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int *_Size;
  uint unaff_ESI;
  uint unaff_EDI;
  int *piVar5;
  undefined1 *puStack_4c;
  undefined1 *puStack_48;
  undefined1 *puStack_44;
  int *piStack_40;
  int *piStack_3c;
  undefined1 *puStack_38;
  undefined4 uStack_34;
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 local_18 [8];
  uint uStack_10;
  int *piStack_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_20;
  if (((*(int *)(in_ECX + 8) != 1) && (*(int *)(in_ECX + 8) != 2)) ||
     (piStack_3c = *(int **)(in_ECX + 0x54), piStack_3c == (int *)0x0)) {
    __security_check_cookie(local_4 ^ (uint)auStack_20);
    return;
  }
  uStack_34 = 0;
  puStack_38 = local_18;
  piStack_40 = (int *)0x69930e;
  iVar2 = (**(code **)(*piStack_3c + 0x10))();
  _Size = piStack_8;
  if (-1 < iVar2) {
    iVar2 = *(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24);
    piVar4 = (int *)(unaff_ESI - *(int *)(in_ECX + 0x1cc));
    if ((int)piVar4 < 0) {
      piVar4 = (int *)((int)piVar4 + iVar2);
    }
    if ((local_4 & 2) == 0) {
      _Size = (int *)(*(int *)(in_ECX + 0x24) * 2);
      if ((int)piVar4 < (int)_Size) {
        _Size = piVar4;
      }
      if (iVar2 < *(int *)(in_ECX + 0x1cc) + (int)_Size) {
        _Size = (int *)(iVar2 - *(int *)(in_ECX + 0x1cc));
      }
    }
  }
  if ((((local_4 & 2) == 0) && (*(int *)(in_ECX + 0x1cc) <= (int)unaff_ESI)) &&
     ((int)unaff_ESI < *(int *)(in_ECX + 0x1cc) + (int)_Size)) {
    __security_check_cookie(uStack_10 ^ (uint)&stack0xffffffd4);
    return;
  }
  piStack_40 = (int *)0x69938d;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
  piVar4 = _Size;
  if (iVar2 - *(int *)(in_ECX + 0x1c8) <= (int)_Size) {
    piStack_40 = (int *)0x6993aa;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
    piVar4 = (int *)(iVar2 - *(int *)(in_ECX + 0x1c8));
  }
  piStack_40 = (int *)0x0;
  puStack_44 = local_18;
  puStack_48 = &stack0xffffffd8;
  puStack_4c = auStack_1c;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x2c))();
  if (iVar2 == -0x7787ff6a) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x50))();
    if (iVar2 < 0) goto LAB_00699626;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x2c))
                      (*(int **)(in_ECX + 0x54),*(undefined4 *)(in_ECX + 0x1cc),_Size,&puStack_4c,
                       &piStack_3c,&puStack_48,&puStack_38);
  }
  if (-1 < iVar2) {
    if (piStack_3c < _Size) {
      piVar5 = (int *)0x0;
    }
    else {
      if ((unaff_ESI & 1) == 0) {
        if ((piVar4 != (int *)0x0) &&
           ((iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x1c))(puStack_4c,piVar4), iVar2 < 0
            || (piStack_40 != piVar4)))) {
          uVar3 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
          *(undefined4 *)(in_ECX + 0x1c8) = uVar3;
          piVar4 = (int *)0x0;
          iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x48))();
          if (-1 < iVar2) {
            *(undefined4 *)(in_ECX + 8) = 0;
          }
        }
      }
      else {
        piVar4 = (int *)0x0;
      }
      piVar1 = piVar4;
      piVar5 = _Size;
      if ((*(byte *)(in_ECX + 0x1d0) & 1) == 0) {
        if ((int)piVar4 < (int)_Size) {
          _memset(puStack_4c + (int)piVar4,0,(int)_Size - (int)piVar4);
          iVar2 = *(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24);
          if (piVar4 == (int *)0x0) {
            if ((int)puStack_44 < (int)DAT_029739f4) {
              iVar2 = iVar2 - (int)DAT_029739f4;
            }
            else {
              iVar2 = -(int)DAT_029739f4;
            }
            DAT_029739f8 = DAT_029739f8 - (int)(puStack_44 + iVar2);
            DAT_029739f4 = puStack_44;
            if (DAT_029739f8 < 1) {
              *(int *)(in_ECX + 0x1d8) = *(int *)(in_ECX + 0x1d8) + 1;
            }
          }
          else {
            DAT_029739f4 = puStack_44;
            DAT_029739f8 = iVar2;
          }
        }
      }
      else {
        for (; (int)piVar1 < (int)_Size; piVar1 = (int *)((int)piVar1 + (int)piVar4)) {
          (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x18))();
          *(undefined4 *)(in_ECX + 0x1c8) = 0;
          piVar4 = (int *)((int)_Size - (int)piVar1);
          iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
          if (iVar2 - *(int *)(in_ECX + 0x1c8) < (int)piVar4) {
            iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
            piVar4 = (int *)(iVar2 - *(int *)(in_ECX + 0x1c8));
          }
          iVar2 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x1c))(puStack_4c + (int)piVar1,piVar4);
          if ((iVar2 < 0) || (piStack_40 != piVar4)) {
            uVar3 = (**(code **)(**(int **)(in_ECX + 0x1dc) + 0x14))();
            *(undefined4 *)(in_ECX + 0x1c8) = uVar3;
            _memset(puStack_4c,0,(size_t)_Size);
            iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x48))();
            if (-1 < iVar2) {
              *(undefined4 *)(in_ECX + 8) = 0;
            }
            break;
          }
        }
      }
    }
    (**(code **)(**(int **)(in_ECX + 0x54) + 0x4c))
              (*(int **)(in_ECX + 0x54),puStack_4c,piVar5,puStack_48);
    *(int *)(in_ECX + 0x1c8) = *(int *)(in_ECX + 0x1c8) + (int)piVar4;
    *(uint *)(in_ECX + 0x1cc) =
         (uint)(*(int *)(in_ECX + 0x1cc) + (int)_Size) %
         (uint)(*(int *)(in_ECX + 0x58) * *(int *)(in_ECX + 0x24));
    __security_check_cookie((uint)puStack_44 ^ (uint)&stack0xffffffa0);
    return;
  }
LAB_00699626:
  __security_check_cookie(unaff_EDI ^ (uint)&puStack_4c);
  return;
}

