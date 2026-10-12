/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a680; label: FUN_0069a680
 */

undefined4 FUN_0069a680(undefined4 param_1,LPVOID param_2,undefined4 param_3,uint *param_4)

{
  LARGE_INTEGER liDistanceToMove;
  BOOL BVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  uint uVar4;
  DWORD nNumberOfBytesToRead;
  uint uVar5;
  DWORD unaff_EDI;
  uint local_c;
  undefined4 local_8 [2];
  
  if (in_ECX[2] != 0) {
    uVar3 = (uint)*(ushort *)(in_ECX + 9);
    uVar4 = in_ECX[0xc] - in_ECX[0xd];
    uVar5 = (uint)param_2 / uVar3;
    if ((int)uVar4 <= (int)((uint)param_2 / uVar3)) {
      uVar5 = uVar4;
    }
    uVar4 = in_ECX[0xd] * uVar3;
    nNumberOfBytesToRead = uVar3 * uVar5;
    local_c = uVar4;
    if (nNumberOfBytesToRead - (int)param_2 != 0) {
      FUN_0069a180();
      uVar4 = FUN_0069a180(param_2,nNumberOfBytesToRead);
    }
    liDistanceToMove.s.HighPart = (LONG)local_8;
    liDistanceToMove.s.LowPart =
         in_ECX[5] + ((int)uVar4 >> 0x1f) + (uint)CARRY4(uVar4,in_ECX[4]) + (in_ECX[0xe] >> 0x1f) +
         (uint)CARRY4(uVar4 + in_ECX[4],in_ECX[0xe]);
    BVar1 = SetFilePointerEx((HANDLE)in_ECX[2],liDistanceToMove,(PLARGE_INTEGER)0x0,unaff_EDI);
    if (BVar1 == 0) {
      FUN_0069a180();
      FUN_0069a180(local_8[0]);
      FUN_0069a180(in_ECX[0xe]);
      uVar2 = (**(code **)(*in_ECX + 0x14))();
      FUN_0069a180(uVar2);
    }
    else {
      BVar1 = ReadFile((HANDLE)in_ECX[2],param_2,nNumberOfBytesToRead,&local_c,(LPOVERLAPPED)0x0);
      if ((BVar1 != 0) && (nNumberOfBytesToRead - local_c == 0)) {
        if (param_4 != (uint *)0x0) {
          *param_4 = local_c;
        }
        in_ECX[0xd] = in_ECX[0xd] + uVar5;
        return 0;
      }
      FUN_0069a180();
      FUN_0069a180(nNumberOfBytesToRead);
      FUN_0069a180(local_c);
      FUN_0069a180(param_3);
    }
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  return 0x80004005;
}

