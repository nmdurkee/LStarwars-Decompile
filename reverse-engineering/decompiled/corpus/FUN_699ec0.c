/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699ec0; label: FUN_00699ec0
 */

void FUN_00699ec0(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  HANDLE pvVar4;
  undefined4 *in_ECX;
  undefined4 *unaff_EBP;
  int *piVar5;
  
  in_ECX[0xfe] = DAT_029739f0;
  DAT_029739f0 = DAT_029739f0 + 1;
  in_ECX[0xff] = param_1;
  in_ECX[6] = param_2;
  puVar1 = in_ECX + 7;
  *in_ECX = 0;
  *puVar1 = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *(undefined2 *)(in_ECX + 0xb) = 0;
  _memset(in_ECX + 0x78,0,0x105);
  _memset((void *)((int)in_ECX + 0x2e5),0,0x105);
  *(undefined2 *)puVar1 = 1;
  switch(in_ECX[6]) {
  case 1:
    *(undefined2 *)((int)in_ECX + 0x1e) = 1;
    in_ECX[8] = 0x5622;
    *(undefined2 *)(in_ECX + 10) = 1;
    *(undefined2 *)((int)in_ECX + 0x2a) = 8;
    in_ECX[0x16] = 4;
    goto switchD_00699f3f_default;
  case 2:
    *(undefined2 *)((int)in_ECX + 0x1e) = 1;
    in_ECX[8] = 0x5622;
    *(undefined2 *)(in_ECX + 10) = 2;
    break;
  case 3:
    *(undefined2 *)((int)in_ECX + 0x1e) = 2;
    in_ECX[8] = 0x5622;
    *(undefined2 *)(in_ECX + 10) = 2;
    *(undefined2 *)((int)in_ECX + 0x2a) = 8;
    goto LAB_00699fff;
  case 4:
    in_ECX[8] = 0x5622;
    goto LAB_00699fed;
  case 5:
    *(undefined2 *)((int)in_ECX + 0x1e) = 1;
    in_ECX[8] = 0xac44;
    *(undefined2 *)(in_ECX + 10) = 2;
    break;
  case 6:
    *(undefined2 *)((int)in_ECX + 0x1e) = 2;
    in_ECX[8] = 0xac44;
    *(undefined2 *)(in_ECX + 10) = 4;
    *(undefined2 *)((int)in_ECX + 0x2a) = 0x10;
    in_ECX[0x16] = 4;
    goto switchD_00699f3f_default;
  case 7:
    *(undefined2 *)((int)in_ECX + 0x1e) = 1;
    in_ECX[8] = 48000;
    *(undefined2 *)(in_ECX + 10) = 2;
    break;
  case 8:
    in_ECX[8] = 48000;
LAB_00699fed:
    *(undefined2 *)(in_ECX + 10) = 4;
    *(undefined2 *)((int)in_ECX + 0x1e) = 2;
    break;
  default:
    goto switchD_00699f3f_default;
  }
  *(undefined2 *)((int)in_ECX + 0x2a) = 0x10;
LAB_00699fff:
  in_ECX[0x16] = 3;
switchD_00699f3f_default:
  in_ECX[9] = (uint)*(ushort *)(in_ECX + 10) * in_ECX[8];
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0xc] = 0x24;
  in_ECX[0xd] = 0x10080;
  in_ECX[0xe] = in_ECX[0x16] * in_ECX[9];
  in_ECX[0x10] = puVar1;
  param_2 = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x18] = 0xffffffff;
  in_ECX[0x17] = 0xffffffff;
  in_ECX[0x70] = 0;
  in_ECX[0x6f] = 0;
  in_ECX[0x6e] = 0;
  in_ECX[1] = 0xffffffff;
  in_ECX[0x74] = 0;
  in_ECX[0xfd] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 1;
  iVar2 = FUN_006ea018(0x338);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0069a850();
  }
  in_ECX[0x77] = uVar3;
  in_ECX[2] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x1c));
  InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x22));
  InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0x28));
  piVar5 = (int *)0x0;
  iVar2 = (**(code **)(*param_1 + 0xc))(param_1,in_ECX + 0xc,&param_2);
  if (-1 < iVar2) {
    iVar2 = (**(code **)*unaff_EBP)(unaff_EBP,&DAT_0078496c,in_ECX + 0x15);
    if (-1 < iVar2) {
      pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
      in_ECX[0x17] = pvVar4;
      pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);
      in_ECX[0x18] = pvVar4;
      if ((in_ECX[0x17] != -1) && (pvVar4 != (HANDLE)0xffffffff)) {
        pvVar4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_00699eb0,
                              in_ECX,4,in_ECX + 0x1b);
        in_ECX[0x1a] = pvVar4;
        if (pvVar4 != (HANDLE)0x0) {
          ResumeThread(pvVar4);
          *in_ECX = 1;
        }
      }
    }
    (**(code **)(*piVar5 + 8))(piVar5);
  }
  return;
}

