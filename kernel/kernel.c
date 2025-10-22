void main()
{
    char *video_memory = (char *) 0xb8000;

    for (int i = 0; i < (320 * 200 * 2); i += 2)
    {
        *(video_memory + i) = '+';
        *(video_memory + i + 1) = 0x1f;
    }
}
