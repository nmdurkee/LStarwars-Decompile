/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69add0; label: FUN_0069add0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069add0(DWORD param_1,LPCSTR param_2,undefined4 *param_3)

{
  LPCSTR pCVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  HANDLE hFile;
  DWORD DVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  int iVar8;
  
  FUN_004ffae0();
  pCVar1 = param_2;
  iVar2 = FUN_004f8a70(param_2,&DAT_0076ef28);
  if (iVar2 == 0) {
    *(undefined1 *)(in_ECX + 0x40) = 0;
    uVar3 = FUN_0069a460(param_1,pCVar1,param_3);
    return uVar3;
  }
  FUN_004ffaa0(DAT_02973a00);
  iVar2 = 0;
  *(undefined1 *)(in_ECX + 0x40) = 1;
  *(undefined4 *)(in_ECX + 0x318) = 0;
  iVar8 = 0;
  do {
    iVar4 = FUN_004f8b10(iVar8 + DAT_029739fc,param_2);
    if ((iVar4 == 0) && (*(int *)(iVar8 + 0x110 + DAT_029739fc) < 1)) {
      *(int *)(in_ECX + 0x318) = iVar2 * 0x114 + DAT_029739fc;
      break;
    }
    iVar8 = iVar8 + 0x114;
    iVar2 = iVar2 + 1;
  } while (iVar8 != 0x564);
  if (*(int *)(in_ECX + 0x318) != 0) {
    *(undefined4 *)(in_ECX + 0x31c) = 0;
    uVar3 = FUN_004ffae0();
    *(undefined4 *)(*(int *)(in_ECX + 0x318) + 0x10c) = uVar3;
    *(int *)(*(int *)(in_ECX + 0x318) + 0x110) = *(int *)(*(int *)(in_ECX + 0x318) + 0x110) + 1;
LAB_0069b08d:
    FUN_004ffae0();
    iVar2 = FUN_0069e990();
    if (-1 < iVar2) {
      iVar2 = FUN_0069d860(in_ECX + 0x48,0);
      *(undefined2 *)(in_ECX + 800) = 1;
      *(undefined2 *)(in_ECX + 0x322) = *(undefined2 *)(iVar2 + 4);
      *(undefined4 *)(in_ECX + 0x324) = *(undefined4 *)(iVar2 + 8);
      iVar8 = *(int *)(iVar2 + 8) * *(int *)(iVar2 + 4) * 0x10;
      *(int *)(in_ECX + 0x328) = (int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3;
      iVar2 = *(int *)(iVar2 + 4) * 0x10;
      *(undefined2 *)(in_ECX + 0x32e) = 0x10;
      *(undefined2 *)(in_ECX + 0x330) = 0;
      *(short *)(in_ECX + 0x32c) = (short)((int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3);
      *param_3 = *(undefined4 *)(in_ECX + 800);
      param_3[1] = *(undefined4 *)(in_ECX + 0x324);
      param_3[2] = *(undefined4 *)(in_ECX + 0x328);
      param_3[3] = *(undefined4 *)(in_ECX + 0x32c);
      *(undefined2 *)(param_3 + 4) = *(undefined2 *)(in_ECX + 0x330);
      FUN_004ffac0(DAT_02973a00);
      return 0;
    }
    if (*(int *)(in_ECX + 0x318) != 0) {
      *(int *)(*(int *)(in_ECX + 0x318) + 0x110) = *(int *)(*(int *)(in_ECX + 0x318) + 0x110) + -1;
    }
    *(undefined4 *)(in_ECX + 0x318) = 0;
    FUN_004ffac0(DAT_02973a00);
    return 0x80004005;
  }
  iVar2 = -1;
  iVar7 = 0;
  iVar8 = -0x114;
  iVar4 = 0;
  do {
    if (*(int *)(iVar4 + 0x110 + DAT_029739fc) < 1) {
      iVar6 = iVar7;
      if (*(int *)(iVar4 + 0x108 + DAT_029739fc) == 0) break;
      if ((iVar2 == -1) ||
         (*(uint *)(iVar4 + 0x10c + DAT_029739fc) < *(uint *)(DAT_029739fc + 0x10c + iVar8))) {
        iVar2 = iVar7;
        iVar8 = iVar4;
      }
    }
    iVar4 = iVar4 + 0x114;
    iVar7 = iVar7 + 1;
    iVar6 = iVar2;
  } while (iVar4 != 0x564);
  if (iVar6 == -1) {
    iVar6 = 0;
  }
  iVar2 = iVar6 * 0x114 + DAT_029739fc;
  *(int *)(in_ECX + 0x318) = iVar2;
  if (*(void **)(iVar2 + 0x104) != (void *)0x0) {
    _memset(*(void **)(iVar2 + 0x104),0xcd,*(size_t *)(iVar2 + 0x108));
    FUN_004ef280(*(undefined4 *)(*(int *)(in_ECX + 0x318) + 0x104),".\\pc\\oggreader.cpp",0x84);
    *(undefined4 *)(*(int *)(in_ECX + 0x318) + 0x104) = 0;
  }
  pCVar1 = param_2;
  hFile = CreateFileA(param_2,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000001,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    *(undefined4 *)(in_ECX + 0x318) = 0;
  }
  else {
    DVar5 = GetFileSize(hFile,(LPDWORD)0x0);
    *(DWORD *)(*(int *)(in_ECX + 0x318) + 0x108) = DVar5;
    iVar2 = *(int *)(*(int *)(in_ECX + 0x318) + 0x108);
    if (0 < iVar2) {
      uVar3 = FUN_004eef40(iVar2,".\\pc\\oggreader.cpp",0xa1);
      *(undefined4 *)(*(int *)(in_ECX + 0x318) + 0x104) = uVar3;
      *(undefined4 *)(in_ECX + 0x31c) = 0;
      if (*(int *)(*(int *)(in_ECX + 0x318) + 0x104) != 0) {
        uVar3 = FUN_004ffae0();
        *(undefined4 *)(*(int *)(in_ECX + 0x318) + 0x10c) = uVar3;
        *(int *)(*(int *)(in_ECX + 0x318) + 0x110) = *(int *)(*(int *)(in_ECX + 0x318) + 0x110) + 1;
        FUN_004f1f10(*(undefined4 *)(in_ECX + 0x318),pCVar1);
        param_1 = 0;
        ReadFile(hFile,*(LPVOID *)(*(int *)(in_ECX + 0x318) + 0x104),
                 *(DWORD *)(*(int *)(in_ECX + 0x318) + 0x108),&param_1,(LPOVERLAPPED)0x0);
        CloseHandle(hFile);
        goto LAB_0069b08d;
      }
    }
    *(undefined4 *)(in_ECX + 0x318) = 0;
    CloseHandle(hFile);
  }
  FUN_004ffac0(DAT_02973a00);
  return 0x80004005;
}

