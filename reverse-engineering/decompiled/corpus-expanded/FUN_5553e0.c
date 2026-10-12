/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x5553e0; label: FUN_005553e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005553e0(void)

{
  char cVar1;
  float *in_EAX;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  
  if ((in_EAX == (float *)0x0) || ((*(byte *)((int)in_EAX + 6) & 1) == 0)) {
    *(undefined2 *)(unaff_ESI + 0x7c) = *(undefined2 *)(unaff_ESI + 0x82);
    FUN_005a1270(*(undefined4 *)(unaff_ESI + 0x68),0);
  }
  else {
    *(undefined2 *)(unaff_ESI + 0x7c) = *(undefined2 *)(in_EAX + 1);
    if (*in_EAX == 1.0) {
      FUN_005a11f0(*(undefined4 *)(unaff_ESI + 0x68));
    }
    else {
      FUN_005a1270(*(undefined4 *)(unaff_ESI + 0x68),*in_EAX);
    }
    if ((*(byte *)((int)in_EAX + 6) & 4) == 0) {
      *(byte *)(unaff_ESI + 0xac) = *(byte *)(unaff_ESI + 0xac) | 2;
    }
    else {
      *(byte *)(unaff_ESI + 0xac) = *(byte *)(unaff_ESI + 0xac) & 0xfd;
    }
    if ((*(byte *)((int)in_EAX + 6) & 2) == 0) {
      *(byte *)(unaff_ESI + 0xac) = *(byte *)(unaff_ESI + 0xac) | 4;
    }
    else {
      *(byte *)(unaff_ESI + 0xac) = *(byte *)(unaff_ESI + 0xac) & 0xfb;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  *(undefined2 *)(unaff_ESI + 0x7e) = *(undefined2 *)(unaff_ESI + 0x7c);
  *(undefined2 *)(unaff_ESI + 0x80) = *(undefined2 *)(unaff_ESI + 0x7c);
  *(undefined1 *)(unaff_ESI + 0x89) = 0xff;
  iVar2 = FUN_005a0f10(*(undefined4 *)(unaff_ESI + 0x68));
  if (iVar2 == 0) {
    cVar1 = (*(int *)(*(int *)(unaff_ESI + 0x68) + 0xc) == 2) + '\x01';
  }
  else {
    cVar1 = '\0';
  }
  *(char *)(unaff_ESI + 0x8a) = cVar1;
  *(uint *)(unaff_ESI + 0x84) = *(uint *)(unaff_ESI + 0x84) & 0xfffffcff | 0x10;
  FUN_005b4670();
  FUN_005b4900();
  FUN_0067a6d0();
  iVar2 = FUN_005cfa20(unaff_ESI + 0x50);
  if (iVar2 == 0) {
    fVar3 = (float10)2e+06;
  }
  else {
    iVar2 = FUN_005cfa20(unaff_ESI + 0x50,0x40a00000,0xffffffff);
    fVar3 = (float10)FUN_005506f0(0,iVar2 + 0x30);
  }
  *(float *)(unaff_ESI + 0xa0) = (float)fVar3;
  if (*(float *)(unaff_ESI + 0xa0) != 2e+06) {
    iVar2 = FUN_0067a600();
    if (iVar2 == 2) {
      *(uint *)(unaff_ESI + 0x84) = *(uint *)(unaff_ESI + 0x84) | 0x800;
    }
  }
  return;
}

