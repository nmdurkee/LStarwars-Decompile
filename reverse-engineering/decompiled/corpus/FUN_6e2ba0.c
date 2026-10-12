/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2ba0; label: FUN_006e2ba0
 */

void FUN_006e2ba0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  
  iVar4 = Direct3DCreate9(0x20);
  *in_ECX = iVar4;
  if (iVar4 == 0) {
    FUN_006e0080(&DAT_02976078,"Failed to initialize DirectX");
  }
  (**(code **)(*(int *)*in_ECX + 0x38))((int *)*in_ECX,0,1,in_ECX + 2);
  (**(code **)(*(int *)*in_ECX + 0x14))((int *)*in_ECX,0,0,in_ECX + 0x69);
  (**(code **)(*(int *)*in_ECX + 0x20))((int *)*in_ECX,0,in_ECX + 0x182);
  iVar4 = in_ECX[0x183];
  iVar1 = in_ECX[0x182];
  iVar5 = FUN_006e1d00(iVar1,iVar4);
  fVar2 = (float)iVar1;
  in_ECX[0x189] = iVar5;
  if (iVar1 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar3 = (float)iVar4;
  if (iVar4 < 0) {
    fVar3 = fVar3 + 4.2949673e+09;
  }
  in_ECX[0x18b] = iVar5;
  in_ECX[0x18a] = (int)(fVar2 / fVar3);
  in_ECX[0x18c] = (int)(fVar2 / fVar3);
  return;
}

