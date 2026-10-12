/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x5738c0; label: FUN_005738c0
 */

void FUN_005738c0(undefined4 param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = FUN_0055e340(&local_c,0);
  if (iVar2 == 0) {
    local_c = *(undefined4 *)(PTR_DAT_008021b4 + 0x11c);
    local_8 = *(undefined4 *)(PTR_DAT_008021b4 + 0x120);
    local_4 = *(undefined4 *)(PTR_DAT_008021b4 + 0x124);
  }
  iVar2 = FUN_00573780(PTR_DAT_00802c54,param_1,&local_c,&local_10);
  if (iVar2 != 0) {
    *(byte *)(param_2 + 0x17) = *(byte *)(param_2 + 0x17) & 0xf9;
    if (*(ushort *)(iVar2 + 0x1e2) < *(ushort *)(iVar2 + 0x1e0)) {
      uVar1 = *(ushort *)(iVar2 + 0x1e2) + 1;
      *(ushort *)(iVar2 + 0x1e2) = uVar1;
      if (uVar1 == *(ushort *)(iVar2 + 0x1e0)) {
        *(byte *)(param_2 + 0x17) = *(byte *)(param_2 + 0x17) | 6;
      }
      if (*(int *)(local_10 + 4) == 0) {
        iVar3 = FUN_005cfac0(local_10 + 8);
        if (iVar3 == 0) {
          param_2 = param_2 + 8;
        }
        else {
          param_2 = FUN_005cf9e0(local_10 + 8);
        }
      }
      else {
        param_2 = FUN_0055a360(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                               *(undefined4 *)(local_10 + 4));
      }
      FUN_00561940(param_2,*(undefined2 *)(iVar2 + 0x1e2),*(undefined2 *)(iVar2 + 0x1e0),
                   *(undefined1 *)(iVar2 + 0x1e4),*(undefined1 *)(iVar2 + 0x1e5),
                   *(undefined1 *)(iVar2 + 0x1e6),0x3f400000);
      FUN_00547930(0x53,0,0,0);
    }
  }
  return;
}

