/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x5601a0; label: FUN_005601a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005601a0(int param_1)

{
  uint *puVar1;
  int iVar2;
  void *_Dst;
  code *pcVar3;
  undefined4 local_8;
  int local_4;
  
  *(undefined4 *)(param_1 + 0x118) = 0;
  DAT_009253a4 = 0;
  DAT_00876d94 = 0;
  local_4 = -1;
  local_8 = 0xffffffff;
  iVar2 = *(int *)(*(int *)(param_1 + 0x128) + 0xc4);
  if (iVar2 == 0) {
    if (DAT_00955b38 != 0) {
      FUN_0055f3e0(1);
    }
  }
  else if ((iVar2 == 2) && (DAT_00955b38 != 0)) {
    *(undefined4 *)(DAT_00955b38 + 0x808) = 0;
  }
  FUN_006508f0();
  FUN_004bde10(param_1);
  _DAT_00924dc8 = FUN_005489b0((int)*(short *)(*(int *)(param_1 + 0x128) + 0x94));
  _DAT_00924ae0 = FUN_00548a10((int)*(short *)(*(int *)(param_1 + 0x128) + 0x94));
  _DAT_00924ae8 = FUN_005489b0((int)*(short *)(*(int *)(param_1 + 0x128) + 0x9c));
  _DAT_009248d4 = FUN_00548a10((int)*(short *)(*(int *)(param_1 + 0x128) + 0x9c));
  _DAT_0093b2ac = _DAT_0093b2ac | 1;
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  FUN_0065b7e0(*(undefined4 *)(param_1 + 0x13c));
  FUN_00659d70(*(undefined4 *)(param_1 + 0x13c));
  FUN_0065b800(*(undefined4 *)(param_1 + 0x295c));
  if (*(int *)(param_1 + 0x2a98) != -1) {
    FUN_0068e890(*(undefined1 *)(param_1 + 0x2a98));
  }
  if (*(int *)(param_1 + 0x2a9c) != -1) {
    FUN_006489f0(*(undefined1 *)(param_1 + 0x2a9c));
  }
  if (*(int *)(param_1 + 0x2aa8) != -1) {
    FUN_00689670(*(undefined1 *)(param_1 + 0x2aa8));
  }
  FUN_0066cb70();
  FUN_0066cbb0(*(undefined4 *)(param_1 + 0x295c));
  FUN_0066cc50((float)*(byte *)(*(int *)(param_1 + 0x128) + 0xcf));
  if (*(int *)(param_1 + 0x2aa4) != -1) {
    FUN_00689c80(*(undefined1 *)(param_1 + 0x2aa4));
  }
  FUN_0068ed90();
  FUN_0066cc60();
  FUN_0066b320(0x3f800000);
  FUN_0057a290(param_1);
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  FUN_005fe610();
  FUN_0068ed90();
  if (*(int *)(param_1 + 0x13c) != 0) {
    FUN_005f4b90(*(int *)(param_1 + 0x13c),0);
  }
  FUN_0066cc60();
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  _Dst = *(void **)(param_1 + 0x130);
  if ((_Dst != (void *)0x0) && ((*(byte *)((int)_Dst + 0x2800) & 1) == 0)) {
    _memcpy(_Dst,(void *)(param_1 + 0x15c),0x2800);
    puVar1 = (uint *)(*(int *)(param_1 + 0x130) + 0x2800);
    *puVar1 = *puVar1 | 1;
  }
  FUN_00575470(param_1);
  FUN_0055ddc0(param_1);
  DAT_0093d504 = *(undefined4 *)(*(int *)(param_1 + 0x298c) + 4);
  FUN_0055c950(*(undefined4 *)(param_1 + 0x298c));
  FUN_005a85d0(param_1);
  FUN_0041f940();
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  FUN_00635a20();
  FUN_0064ae40(*(undefined4 *)(param_1 + 0x2ab4));
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  *(undefined1 *)(param_1 + 0x2990) = 1;
  *(void **)(param_1 + 0x2a94) = (void *)(param_1 + 0x2991);
  _memset((void *)(param_1 + 0x2991),0,0x100);
  pcVar3 = *(code **)(*(int *)(param_1 + 0x128) + 0x6c);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param_1);
  }
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  if (DAT_00947bb0 != (code *)0x0) {
    (*DAT_00947bb0)(param_1,&local_4,&local_8);
  }
  if (DAT_00803d8c != -1) {
    local_4 = DAT_00803d8c;
    local_8 = DAT_00951bd8;
    DAT_00803d8c = -1;
    DAT_00951bd8 = 0xffffffff;
  }
  iVar2 = *(int *)(param_1 + 300);
  if (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x7a) & 4) == 0) {
      if (iVar2 == DAT_00951364) {
        DAT_0093b29c = 0;
        DAT_0093b2a4 = 0;
      }
    }
    else {
      DAT_0093b29c = 1;
      DAT_0093b2a4 = 1;
    }
  }
  FUN_00509760();
  FUN_00509830(local_4,local_8,0xffffffff);
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  FUN_00548fb0(&DAT_0092509c,0);
  if ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 0xe0) == 0) {
    FUN_0055f5d0(param_1);
  }
  *(undefined4 *)(param_1 + 0x114) = 1;
  DAT_008765c4 = 1;
  FUN_00595a10();
  *(undefined4 *)(param_1 + 0x5170) = 1;
  _DAT_00803570 = 0x3f800000;
  _DAT_0080357c = 0x3f800000;
  _DAT_00803574 = 0x2000;
  _DAT_008035e8 = 0x3f800000;
  _DAT_00803580 = 0x2000;
  _DAT_008035b8 = 0x3f800000;
  _DAT_008035ec = 0x2000;
  _DAT_00803534 = 0x3f800000;
  _DAT_008035bc = 0x2000;
  _DAT_00803538 = 0x2000;
  if (DAT_00947bb4 != (code *)0x0) {
    (*DAT_00947bb4)(param_1);
  }
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  return;
}

