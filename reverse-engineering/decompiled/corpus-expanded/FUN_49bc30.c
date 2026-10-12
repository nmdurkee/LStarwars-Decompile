/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49bc30; label: FUN_0049bc30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049bc30(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  float local_c [2];
  float local_4;
  
  if ((((*(char *)(param_2 + 0x7b5) != '=') && (*(char *)(param_2 + 0x7b5) != '3')) &&
      (iVar2 = *(int *)(*(int *)(param_2 + 0x54) + 0x24), (*(byte *)(iVar2 + 0x90) & 0x40) == 0)) &&
     (((*(float *)(iVar2 + 0x28) == 0.0 || (*(char *)(param_2 + 0xe32) != '\x01')) &&
      (((*(byte *)(param_1 + 0x1fc) & 4) == 0 && (*(char *)(param_2 + 0x281) != '\0')))))) {
    FUN_0055e4a0(param_2,0);
    FUN_0055e4e0(param_2 + 0x6c4);
    *(undefined1 *)(param_2 + 0x7b5) = 0x3d;
    iVar2 = *(int *)(*(int *)(*(int *)(param_2 + 0x50) + 0xc) + 0x214);
    *(float *)(param_2 + 0x68) = *(float *)(param_2 + 0x68) * 0.5;
    *(ushort *)(param_2 + 0x7aa) = (-(ushort)(iVar2 != 0) & 0x80) + 5;
    *(float *)(param_2 + 0x70) = *(float *)(param_2 + 0x70) * 0.5;
    *(undefined4 *)(param_2 + 0x77c) = 0;
    iVar2 = FUN_0054fa60();
    *(float *)(param_2 + 0x784) = (float)iVar2 * 1.5259022e-05 + 1.0;
    FUN_005b3800(local_c,param_2 + 0x80,param_1 + 0x80);
    sVar1 = FUN_005be2d0(local_c[0],local_4);
    if (0.0 <= *(float *)(param_2 + 0xf38) * local_4 + *(float *)(param_2 + 0xf30) * local_c[0]) {
      *(undefined1 *)(param_2 + 0x7b3) = 0;
    }
    else {
      sVar1 = sVar1 + -0x8000;
      *(undefined1 *)(param_2 + 0x7b3) = 1;
    }
    if (*(short *)(param_2 + 0x7aa) != 0x85) {
      *(short *)(param_2 + 0x27a) = sVar1;
      *(short *)(param_2 + 0x58) = sVar1;
      *(short *)(param_2 + 0x5a) = sVar1;
    }
    *(undefined4 *)(param_2 + 0xd48) = 0;
    FUN_0054a8d0(**(undefined4 **)(param_1 + 0xca4),1,0);
    FUN_005478a0((int)*(short *)(*(int *)(*(int *)(param_2 + 0x54) + 0x24) + 0xde),param_2 + 0x80,0,
                 0);
    FUN_0054a8a0(**(undefined4 **)(param_2 + 0xca4),0x3dcccccd,0);
  }
  return;
}

